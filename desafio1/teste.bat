gcc -c requisicao.c
gcc -c estrutura.c
gcc teste.c requisicao.c estrutura.c -o teste_exe.exe
teste_exe.exe