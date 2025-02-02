#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED_PIN 13
#define LED_YELLOW_PIN 12
#define LED_GREEN_PIN 11
#define INTERVAL_MS 3000

volatile int led_state = 0; // Começa no estado 0, que é o vermelho

bool repeating_timer_callback(struct repeating_timer *t)
{
    // Desliga todos os LEDs antes de ligar o próximo
    gpio_put(LED_RED_PIN, 0);
    gpio_put(LED_YELLOW_PIN, 0);
    gpio_put(LED_GREEN_PIN, 0);

    // Alterna os estados dos LEDs
    if (led_state == 0)
    {
        gpio_put(LED_RED_PIN, 1);
    }
    else if (led_state == 1)
    {
        gpio_put(LED_YELLOW_PIN, 1);
    }
    else
    {
        gpio_put(LED_GREEN_PIN, 1);
    }

    // Atualiza o estado do LED
    led_state = (led_state + 1) % 3;

    return true; // Mantém o temporizador repetindo
}

int main()
{
    stdio_init_all(); // Inicializa a comunicação serial

    // Configura os pinos dos LEDs como saída
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_init(LED_YELLOW_PIN);
    gpio_set_dir(LED_YELLOW_PIN, GPIO_OUT);
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);

    // Garante que o LED vermelho está ligado inicialmente
    gpio_put(LED_RED_PIN, 1);

    struct repeating_timer timer;

    // Inicia o temporizador para alternar os LEDs a cada 3 segundos
    add_repeating_timer_ms(INTERVAL_MS, repeating_timer_callback, NULL, &timer);

    while (true)
    {
        printf("Semáforo em funcionamento...\n");
        sleep_ms(1000); // Aguarda 1 segundo antes de imprimir novamente
    }

    return 0;
}
