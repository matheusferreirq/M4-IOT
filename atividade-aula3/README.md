# 💡 Atividade em Aula – Programação Orientada a Objetos com Arduino

Este repositório contém o código desenvolvido em aula para aplicar conceitos de **Programação Orientada a Objetos (POO)** utilizando o Arduino UNO.
O objetivo foi criar uma classe controladora de LEDs, encapsulando o comportamento de acender e apagar os LEDs conectados a diferentes portas digitais.

## 🧠 Conceito aplicado

A classe ControladorLed foi criada para representar um objeto responsável por controlar dois LEDs, armazenando internamente:

- o estado atual do LED (aceso ou apagado);
- as portas digitais configuradas (porta 7 e 8);
- e métodos de controle com feedback via Serial Monitor.

### ⚙️ Código Utilizado
```
int porta1x = 7;
int porta2x = 8;

class ControladorLed {
    bool estado_;
    int porta_1_, porta_2_;
public:
    ControladorLed(int porta1, int porta2) 
        : estado_(false), porta_1_(porta1), porta_2_(porta2) {}

    void acender(int porta) {
        if ((porta == porta_1_ || porta == porta_2_) && estado_ == false) {
            estado_ = true;
            digitalWrite(porta, HIGH);
            Serial.print("Led da porta ");
            Serial.print(porta);
            Serial.println(" esta aceso!");
        }
    }

    void apagar(int porta) {
        if ((porta == porta_1_ || porta == porta_2_) && estado_ == true) {
            estado_ = false;
            digitalWrite(porta, LOW);
            Serial.print("Led da porta ");
            Serial.print(porta);
            Serial.println(" esta apagado!");
        }
    }
};

ControladorLed leds(porta1x, porta2x);

void setup() {
    Serial.begin(9600);
    pinMode(porta1x, OUTPUT);
    pinMode(porta2x, OUTPUT);
}

void loop() {
    delay(1000);
    leds.apagar(porta1x);
    delay(1000);
    leds.acender(porta2x);
    delay(1000);
    leds.apagar(porta2x);
    delay(1000);
    leds.acender(porta1x);
}
```
## 🧩 Explicação do Funcionamento

- A classe encapsula o estado e os métodos de controle, aplicando encapsulamento e abstração.
- Cada chamada de acender() ou apagar() altera o estado do LED e registra uma mensagem no Serial Monitor.
- O loop principal alterna entre os dois LEDs com intervalos de 1 segundo, simulando uma sequência intermitente.

--- 

🔗 Simulação no Tinkercad: [Clique aqui!](https://www.tinkercad.com/things/5JBaDFv5Myg-surprising-gogo/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=WLlFU6oLM3PGsgF3sCpQ9o9_h9MqkxmYQonctJcPm2w)