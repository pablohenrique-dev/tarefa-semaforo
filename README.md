# Atividade 1: Temporizador periódico.

## 📌 Introdução

Este projeto consiste na implementação de um semáforo utilizando a placa **Raspberry Pi Pico W**, a biblioteca **Pico SDK** e a função **add_repeating_timer_ms()** para controlar a temporização. A cada 3 segundos, o sinal do semáforo será alterado de acordo com o fluxo normal de trânsito:

1. **Vermelho** → Parada.
2. **Verde** → Siga.
3. **Amarelo** → Atenção.

## 📜 Funcionamento

A função **add_repeating_timer_ms()** da **Pico SDK** permite a execução de uma tarefa em intervalos de tempo específicos. No caso do semáforo, a cada **3 segundos**, a cor do LED será alterada conforme o seguinte ciclo:

1. **LED Vermelho aceso** por 3 segundos.
2. **LED Verde aceso** por 3 segundos.
3. **LED Amarelo aceso** por 3 segundos.
4. Repete o ciclo.

A programação será feita em **C/C++** utilizando o **Pico SDK**.
