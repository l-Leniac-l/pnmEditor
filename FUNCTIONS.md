## Trabalho prático 03
### Inf 110

#### Argumentos do programa.

    -lighten 50

Clareia a imagem em um fator de `50`. Caso `valor` seja negativo, imagem será
 escurecida.

    -darken 80

Escurece a imagem em um fator de `80`. Caso `valor` seja negativo, a imagem será
 clareada.

    -pixelate 5

Pixeliza a imagem, com uma intensidade igual a `5`. Caso `n` seja <= 0, nada
 será feito.


    -mirror

Espelha a imagem horizontalmente.

    -negativate

Inverte as cores da imagem.

    -sobel

Aplica o filtro sobel na imagem.

    -gaussian

Aplica o gaussian blur na imagem.

    -box

Aplica o box blur na imagem.

    -laplace

Aplica o filtro laplace na imagem.

    -greyscale

Converte as bandas da imagem para preto-e-branco utilizando o luma como
referência. As operações para imagens coloridas continuarão sendo
utilizadas.

    -p2 saida.pnm

Converte a imagem para preto-e-branco e a Exporta para o arquivo `saida.pnm`.

    -p3 saida.pnm

Exporta para o arquivo `saida.pnm` o buffer atual como uma imagem colorida.

##### Obs: Alguns exemplos de imagens utilizando estes efeitos estão no diretório `<sources>/examples` 
