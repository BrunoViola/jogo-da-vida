# jogo-da-vida
  Este foi um trabalho desenvolvido em linguagem C durante o 1° Semestre da faculdade de Ciência da Computação, na disciplina de Algoritmos. Dessa forma, o Jogo da Vida se trata de um jogo de simulação (ou "zero-player"), no qual um quadro possuirá células que podem estar "vivas" ou "mortas" ao passar das gerações. O status de uma célula pode ser alterado entre uma geração e outra a depender de certas regras que serão expostas adiante.
  O código aqui apresentado considera um quadro com dimensões 30x30. Sendo o conjunto de regras, que estabelece se a célula estará viva (representada como 1) ou morta (simbolizado pelo número 0), o seguinte:
    • Uma célula viva com menos que dois vizinhos vivos, morre na próxima geração;
    • Uma célula viva com mais de três vizinho vivos também morre;
    • Uma célula viva com exatamente dois ou três vizinhos vivos, também vive;
    • Uma célula morta com exatamente 3 vizinho vivos, torna-se viva.
    
  Adicionalmente, o programa faz a leitura de um arquivo texto com a dimensão 30x30 e da quantidade de gerações a serem simuladas, exibindo-as com um intervalo de tempo.
