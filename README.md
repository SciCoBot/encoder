# Biblioteca encoder para Arduino Due
[![platform badge](https://img.shields.io/badge/platform-Arduino-orange.svg)](https://github.com/arduino)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/SciCoBot/led_debug/blob/main/LICENSE)

## Contents

- [Sobre](#sobre)
- [Comandos Básicos](#comandos-básicos)
- [Como Utilizar](#como-utilizar)
- [Implementações Futuras](#implementações-futuras)

## Sobre

Está biblioteca tem como objetivo fornecer funções e macros para sensor encoder HC-020K. 

Em resumo, a biblioteca utiliza o pino indicado como interrupção. Por default, esperasse que a interrupção ative sempre que o estado do pino for de HIGH para LOW, ou seja quando passa de um furo para uma obstrução no disco do encoder.

## Comandos Básicos

### Definições:
- COUNTS_PER_REV: quantidade de furos do disco encoder.
- ENCODER_DEBUG: utilizado para habilitar ou desabilitar mensagens debug padrão. Utilize 1 para habilitar. Por default é igual a 0.

### Funções:
- **getRpm():** calcula e retorna a velocidade em RPM;
- **init(pinDigital, functionInterrupt)):** um objeto deve primeiro ser iniciado para o correto funcionamento da biblioteca. Esta função seta os valores iniciais das variáveis de classe e inicia a interrupção utilizando o pino e o modo fornecido.
- **read():** retorna a quantidade de pulsos.
- **readAndReset():** retorna a quantidade de pulsos e zera o valor.
- **incrementPulses():** soma mais um no vlaor de pulso.

## Como Utilizar

- Baixe.

- Adicione a partir da IDE arduino: Sketch -> Include Library -> Add .ZIP Library... -> selecione o arquivo baixado na etapa anterior.

- Teste o exemplo.

## Implementaçõs Futuras
- Implementar init() que recebe o endereço de uma função externa a biblioteca.


