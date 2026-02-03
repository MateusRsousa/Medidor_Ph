#include <Arduino.h>
#include "Display.h"
#include "SensorPh.h"
#include "List.h"

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define BUTTON_SAVE 35
#define BUTTON_SHOW_LIST 18
#define BUTTON_EXCLUDE_LIST 13


float valordePh = 0;
String currentTime;

//variáveis para os botões
bool showList = false;
int estadoatual = HIGH;
unsigned long lastDebounceTimeSave = 0;
unsigned long lastDebounceTimeShow = 0;
const unsigned long debounceDelay = 200;
bool saveButtonPressed = false;
bool showButtonPressed = false;
bool excludeButtonPressed = false;

Display display(0x3F, 16, 2); // Endereço 0x3F, 16 colunas e 2 linhas
Sensor* sensor = new SensorPh();
List lista1;
Clock myClock;

QueueHandle_t phQueue;

void updateButtonState();
void phTask(void* parameter);



void setup() {

phQueue = xQueueCreate(5, sizeof(float));
xTaskCreate(
        phTask,               // Função da tarefa
        "pHTask",             // Nome da tarefa
        1000,                 // Tamanho da stack
        NULL,                 // Parâmetro da tarefa
        1,                    // Prioridade
        NULL                  // Handle da tarefa
    );

pinMode(BUTTON_SAVE, INPUT_PULLUP);
pinMode(BUTTON_SHOW_LIST, INPUT_PULLUP);
pinMode(BUTTON_EXCLUDE_LIST, INPUT_PULLUP);
  
  display.init();
  display.clear();
  display.backlight();
  myClock.init();
  myClock.setDateTime(2024, 12, 9, 11, 00, 0);
    
  }

void loop() {

  updateButtonState();
  display.setCursor(0, 0); 
  
  display.print(valordePh, 1);

  display.setCursor(0, 1); 
  currentTime = myClock.getDateTime();
  display.print(currentTime);


  

    if (showList) {
        
        lista1.listAll(display, myClock);

        
        while (digitalRead(BUTTON_SHOW_LIST) == LOW) {
            delay(10); 
        }
        showList = false; // Sai do modo de exibição da lista
        display.clear();  
        delay(500);
    } 

     if (saveButtonPressed) {
       
            lista1.insertAfterLast(valordePh,currentTime);
           
            saveButtonPressed = false; 
        }

         if (excludeButtonPressed) {
       
            lista1.removeAll();
           
            excludeButtonPressed = false; 
        }

 float updatedPh;
    if (xQueueReceive(phQueue, &updatedPh, 0) == pdPASS) {
        valordePh = updatedPh;
    }


}



void updateButtonState() {
    int buttonSaveState = digitalRead(BUTTON_SAVE);
    int buttonShowState = digitalRead(BUTTON_SHOW_LIST);
    int buttonExcludeState = digitalRead(BUTTON_EXCLUDE_LIST);

    if (buttonSaveState == HIGH ) {
        saveButtonPressed = true;
        lastDebounceTimeSave = millis();
        delay(1000);
    }

    if (buttonShowState == HIGH ) {
        showList = true;
        lastDebounceTimeShow = millis();
        delay(1000);
    }

    if (buttonExcludeState == HIGH ) {
        excludeButtonPressed = true;
        lastDebounceTimeShow = millis();
        delay(1000);
    }
}

void phTask(void* parameter) {
    for (;;) {
        float phValue = sensor->getValue();

        // Envia o valor para a fila
        xQueueSend(phQueue, &phValue, portMAX_DELAY);

        // Aguarda 1 segundo antes de ler novamente
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
