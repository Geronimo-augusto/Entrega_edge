# Sistema de Monitoramento de pH e Temperatura
Este é um sistema simples de monitoramento de pH e temperatura, que utiliza sensores DHT e um potenciômetro para medir esses parâmetros. O sistema exibe alertas no LCD e registra eventos fora dos limites de pH e temperatura no monitor serial.

## Requisitos
- Arduino IDE: O código foi desenvolvido para ser executado no Arduino.
- Bibliotecas: Certifique-se de ter as bibliotecas necessárias instaladas. As bibliotecas usadas são:
    - Wire.h
    - LiquidCrystal.h
    - RTClib.h
    - DHT.h
## Configuração
Antes de usar o sistema, é necessário configurar as definições de pinos e os limites de temperatura e pH no código.

- Definições de pinos: Configure os pinos usados para conectar os sensores DHT e o potenciômetro. O pino de dados do DHT, o tipo de sensor DHT e o pino analógico para o potenciômetro são definidos no início do código.
- Limites de temperatura e pH: Defina os limites mínimo e máximo de temperatura e pH no código.
## Funcionamento do Código
## Configuração Inicial
A função `setup()` inicializa as comunicações serial e I2C, o sensor DHT, o LCD e o RTC. Após a inicialização, exibe uma mensagem no LCD indicando que o sistema está pronto.

## Loop Principal
O loop principal (`loop()`) realiza a leitura da temperatura e umidade do sensor DHT e do pH simulado pelo potenciômetro. Em seguida, verifica se os valores lidos estão dentro dos limites especificados. Se estiverem dentro dos limites, as leituras normais são exibidas no LCD. Caso contrário, é exibido um alerta no LCD e os dados são registrados no monitor serial.

## Verificação do RTC
A função `rtc_verifc()` verifica se o RTC está funcionando corretamente. Se o RTC não for encontrado ou perder energia, ele ajusta a data e hora com base na data e hora de compilação do código.

## Registro Serial de Alertas
A função `serial_register()` registra os alertas no monitor serial juntamente com a data, hora, temperatura e pH detectados.

# Links
https://wokwi.com/projects/399354220252272641
https://github.com/Geronimo-augusto/Entrega_edge/edit/main/README.md
https://www.youtube.com/watch?v=eWRRK9iFzcA

## Autores
- Geronimo Augusto RM- 557170
- Murilo Cordeiro RM- 556727
