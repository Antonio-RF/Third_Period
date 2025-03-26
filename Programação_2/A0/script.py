import subprocess

#T1: Insere um, consome um
def exec_t1():
	return b'1\nLala\n10\n2\n3'

#T2: Insere um com valor 5, insere um com o valor 10 e insere um com o valor 1, consome três
def exec_t2():
	return b'1\nLala\n5\n1\nLele\n10\n1\nLili\n1\n2\n2\n2\n3'

#T3: Insere um com valor 10, insere um com o valor 1, insere um com o valor 5, insere um com o valor 6, insere um com o valor 4, consome cinco
def exec_t3():
	return b'1\nLala\n10\n1\nLele\n1\n1\nLili\n5\n1\nLolo\n4\n1\nLulu\n6\n2\n2\n2\n2\n2\n3'

#T4: Insere um, consome dois
def exec_t4():
	return b'1\nLala\n10\n2\n2\n3'

#T5: Insere dois
def exec_t5():
	return b'1\nLala\n5\n1\nLele\n10\n3'
	

test_list = [exec_t1, exec_t2, exec_t3, exec_t4]
valgrind_list = ["Base/Valgrind-1", "Base/Valgrind-2"]

p = subprocess.run(['make'], stdout=subprocess.PIPE)
if not p.returncode:
	for i in range(len(test_list)):
		p = subprocess.run(['./jukebox'], stdout=subprocess.PIPE, input=test_list[i]())
		print("\n========================== TESTE", i+1, "==========================\n")
		if not p.returncode:
			print("DIFF - RESULTADO:")
			a = open("ResultadoT" + str(i+1) + ".txt", "w+")
			a.write(p.stdout.decode('utf-8'))
			a.close()
			try:
				subprocess.check_call(['diff', "ResultadoT" + str(i+1) + ".txt", "Base/ResultadoT" + str(i+1) + ".txt"])
			except:
				continue
		else:
			print("ERRO NO TESTE #" + str(i+1))
		print ("\n=============================================================\n\n")

	for i in range(len(valgrind_list)):
		e = open(valgrind_list[i], 'r')
		print("\n==================== VALGRIND", i+1, "=====================\n")
		try:
			subprocess.check_call(['valgrind', './jukebox'], stdout=subprocess.PIPE, stdin=e)
		except:
			continue
		print ("=============================================================\n\n")
		e.close()


	subprocess.call(["make", "clean"], stderr=subprocess.PIPE)
else:
	print("ERRO DE COMPILAÇÃO")
