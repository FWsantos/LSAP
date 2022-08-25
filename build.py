# Build Script
import os
# os.system('cls') #windows
os.system('clear') #linux

# Compila
command = "g++ "
command += "-std=c++2a "
command += "-c "
command += "-Wall "
command += "LSAP.cpp "
command += "main.cpp "

erro = os.system(command)

# Linka
if erro == 0:
	command = "g++ "
	command += "-o "
	command += "LSAP.exe "
	command += "LSAP.o "
	command += "main.o "
	erro = os.system(command)

	# APaga os object e executa o .exe
	os.system("rm -rf *.o")
	if erro == 0: 
		os.system("echo 'Buildado com sucesso'")
		os.system("./LSAP.exe")
		# os.system("./LSAP")