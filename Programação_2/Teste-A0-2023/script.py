import sys
import subprocess

def make_t1(init):
	return b'2\n3\n'

def make_t2(init):
	if init:
		return b'1\n0\na\naa\n1\n0\nb\nbb\n1\n0\nc\ncc\n2\n2\n3\n'
	else:
		return b'1\na\naa\n0\n1\nb\nbb\n0\n1\nc\ncc\n0\n2\n2\n3\n'

def make_t3(init):
	if init:
		return b'1\n1\na\naa\n1\n1\nb\nbb\n1\n1\nc\ncc\n2\n2\n3\n'
	else:
		return b'1\na\naa\n1\n1\nb\nbb\n1\n1\nc\ncc\n1\n2\n2\n3\n'

def make_t4(init):
	if init:
		return b'1\n0\na\naa\n1\n0\nb\nbb\n1\n0\nc\ncc\n1\n1\nd\ndd\n2\n2\n3\n'
	else:
		return b'1\na\naa\n0\n1\nb\nbb\n0\n1\nc\ncc\n0\n1\nd\ndd\n1\n2\n2\n3\n'

def make_t5(init):
	if init:
		return b'1\n1\na\naa\n1\n1\nb\nbb\n1\n0\nc\ncc\n2\n1\n1\nd\ndd\n2\n3\n'
	else:
		return b'1\na\naa\n1\n1\nb\nbb\n1\n1\nc\ncc\n0\n2\n1\nd\ndd\n1\n2\n3\n'

def make_t6(init):
	if init:
		return b'1\n1\na\naa\n1\n0\nb\nbb\n1\n0\nc\ncc\n2\n1\n0\nd\ndd\n1\n0\ne\nee\n1\n0\nf\nff\n1\n0\ng\ngg\n1\n0\nh\nhh\n1\n0\ni\nii\n2\n2\n2\n2\n3\n'
	else:
		return b'1\na\naa\n1\n1\nb\nbb\n0\n1\nc\ncc\n0\n2\n1\nd\ndd\n0\n1\ne\nee\n0\n1\nf\nff\n0\n1\ng\ngg\n0\n1\nh\nhh\n0\n1\ni\nii\n0\n2\n2\n2\n2\n3\n'

if len(sys.argv) ==1:
	INIT = False
else:
	INIT = eval(sys.argv[1])

test_list = [make_t1, make_t2, make_t3, make_t4, make_t5, make_t6]

for i in range(len(test_list)):
	p = subprocess.run(['./main'], stdout=subprocess.PIPE, input=test_list[i](INIT))
	print("\n========================== TESTE", i+1, "==========================\n")
	if not p.returncode:
		print(p.stdout.decode('utf-8'))
	else:
		print("ERRO NO TESTE #" + str(i+1))
	print ("=============================================================\n\n")

