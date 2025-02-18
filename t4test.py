#!/usr/bin/python3
import os
import signal
import sys
import tempfile
import subprocess
import glob
import shutil
import re
import time
import csv
import threading

'''
This class takes the place of sys.stdout. It intercepts whatever is
being written to the console and writes it the console, a file, and
a local data structure.
In other words, whatever you print here or in your program also
prints to the file and to a list. The list can then be searched for 
proper output. 
'''
class Tee(object):
	def open(self, name, mode):
		sys.stdout.flush()
		self.file = open(name, mode)
		self.stdout = sys.stdout
		sys.stdout = self
		#self.data = []
	def close(self):
		sys.stdout = self.stdout
		self.file.close()
	def write(self, data):
		self.file.write(data)
		self.stdout.write(data)
		#if data != '\n':
			#self.data.videoend(data)
	def flush(self):
		self.file.flush()
		self.stdout.flush()
		
verbose = False

def kill_proc(proc, timeout):
	# you must have done something wrong
	# to end up here
	timeout["value"] = True
	proc.kill()

# a run with timeout function 
def run_with_timeout(cmd, timeout_sec, stdinput):
	print("Running: ",cmd)
	proc = subprocess.Popen(cmd,stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	timeout = {"value": False}
	timer = threading.Timer(timeout_sec, kill_proc, [proc, timeout])
	timer.start()
	(out, err) = proc.communicate(input = stdinput.encode("utf-8"))
	out = out.decode("utf-8")
	err = err.decode("utf-8")
	if len(out) < 1000:
		print(out)
	else:
		#wow you printed a lot of stuff
		print(out[:1000] + "...")
	if verbose:
		print(err)
	timer.cancel()
	return proc.returncode, timeout["value"], out, err

	
def run(cmd, time, stdinput="", testlist = []):
	#print("Running: {}\n".format(cmd))
	print("Executing: {}".format(" ".join(cmd)))
	try:
		
		# just in case we will kill your process 
		# after <time> seconds
		res, timeout, out, err = run_with_timeout(cmd, time, stdinput)
	except:
		print("An exception occurred")
		print("{} test failed!".format(" ".join(cmd)))
		return 0
	if timeout:
		print("Taking too long, abort")
		print("Could be an infinite loop or segmentation fault")
		return 0
	if res == 0:
		# program ran and nothing crashed. Check the output
		if len(testlist)==0:
			print("Test passed")
			return 2
		score = 0
		#save the last thing written to cout
		for e in testlist:
			if (out.find(e) == -1 and err.find(e) == -1):
				print("'"+e+"' not found")
			else:
				print("'"+e+"' found, 2 marks")
				score+=2
		return score
	else: 
		print("Program exited with non-zero status, test failed")
	return 0

def test(dirname, outof):


		
	#switch to directory dirname
	os.chdir(dirname)
	sys.stdout.flush()
	print("\n{stars}\n* Compilation\n{stars}".format(stars="*"*75))
	
	# run the 'make clean' and 'make all' commands
	cmds = ["clean","test", "test2"]
	for c in cmds:
		cmd = ["make",c]
		print("Executing: {}".format(" ".join(cmd)))
		res = subprocess.call(cmd)
		sys.stdout.flush()
		if res:
			# make command produced an error
			print("make: non-zero exit status {}".format(res))
			#print("\n\n{stars}\n* Mark: {mark}/{outof}\n".format(stars="*"*75, mark=0, outof=outof))
			#return
		
	score = 0
	
	#arguments are:
	#<command, timeout, input, find in output, score per string found>
		
	args=['0','1','2','3', '4']
	output = [['Review', 'Playthrough', 'Podcast', 'picture'], ['Video', 'Title', 'CleverTitle', 'DUPLICATE'],['Review', 'Playthrough', 'Podcast', 'picture'], ['Video', 'Title', 'CleverTitle', 'DUPLICATE'], ['Review', 'Playthrough', 'Podcast', 'picture']]
	out = ['stack object array','stack pointer array', 'heap object array', 'heap pointer array', 'const test']
	
	for i in range(4):
		print("\nTesting "+out[i]+'\n')
		score += run(["valgrind","./test"], 5, " ".join([args[i]]+output[i]), output[i]+["All heap blocks were freed -- no leaks are possible"])

	score += 5*run(["./test2"], 5, " ".join([args[4]]))

	print("\n\n{stars}\n* Mark: {mark}/{outof}\n{stars}\n".format(stars="*"*75, mark=score, outof=outof))



	
def process_all():
	global verbose

	verbose = True

			
	t = Tee()
	
	
	
	t.open('results.txt', 'w')
	
	dirname = 'tutorial4'
	#dirname = '.'
	test(dirname, 50)
		
	t.close()




if __name__ == "__main__":
	
	sys.stdout.flush()
	process_all()
	sys.stdout.flush()
	
