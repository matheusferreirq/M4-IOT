// importa bibliotecas necessárias
#include <Wire.h>

// setup do LCD 

// variáveis para os pinos conectados no arduino
int ledVerdeSemaforo13 = 3;
int ledAmareloSemaforo13 = 2;
int ledVermelhoSemaforo13 = 7;
int ledVerdeSemaforo2 = 3;
int ledAmareloSemaforo2 = 2;
int ledVermelhoSemaforo2 = 7;
int botao = 9;
bool fluxoAlto = false;

// setup das entradas do arduino
void setup() {

  Serial.begin(9600);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(botao, INPUT_PULLUP); 
}

// criação da classe Led, que tem como métodos acender, apagar e mostrarComTempo
class Led {
  int porta_;
  bool estado_;
public:
  Led(int porta) : porta_(porta), estado_(false) {}

  void acender() {
    if (!estado_) {
      estado_ = true;
      digitalWrite(porta_, HIGH);
    }
  }

  void apagar() {
    if (estado_) {
      estado_ = false;
      digitalWrite(porta_, LOW);
    }
  }

  void mostrarComTempo(int* tempoPtr, const char* cor, const char* mensagem) {
    acender();
    for (int t = *tempoPtr; t > 0; t--) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sinal: ");
      lcd.print(cor);
      lcd.setCursor(0, 1);
      lcd.print(mensagem);
      lcd.print(" ");
      lcd.print(t);
      lcd.print("s");
      delay(1000);
    }
    apagar();
  }
};

// criação dos objetos da classe Led
Led vermelho(7);
Led amarelo(2);
Led verde(3);

void loop() {
  // inicializa as variáveis de tempo padrão para cada cor do semáforo
  int tempoVermelho = 6;
  int tempoVerde = 4;
  int tempoAmarelo = 2;

  // cria ponteiros para as variáveis de tempo
  int* ptrVermelho = &tempoVermelho;
  int* ptrVerde = &tempoVerde;
  int* ptrAmarelo = &tempoAmarelo;

  // verifica se o botão foi pressionado
  if (digitalRead(botao) == LOW) {
    // se o botão foi pressionado, aumenta o tempo do sinal verde
    *ptrVerde = 8;
    lcd.clear();
    // exibe mensagem de fluxo alto e tempo de verde alterado
    lcd.setCursor(0, 0);
    lcd.print("Fluxo alto!");
    lcd.setCursor(0, 1);
    lcd.print("Verde = 8s");
    // pequeno atraso para a mensagem ser lida
    delay(1500);
  } else {
    // se o botão não foi pressionado, mantém o tempo padrão para o sinal verde
    *ptrVerde = 4;
  }

  // aciona o sinal VERMELHO, mostrando a mensagem e contagem regressiva no LCD
  vermelho.mostrarComTempo(ptrVermelho, "VERMELHO", "PARE");
  // aciona o sinal VERDE, mostrando a mensagem e contagem regressiva no LCD
  verde.mostrarComTempo(ptrVerde, "VERDE", "SIGA");
  // aciona o sinal AMARELO, mostrando a mensagem e contagem regressiva no LCD
  amarelo.mostrarComTempo(ptrAmarelo, "AMARELO", "ATENCAO");
}