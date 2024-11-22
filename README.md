# Monitoramento de Sensores com ESP32 e Thinger.io

## Proposta do Projeto
Este projeto tem como objetivo monitorar e exibir dados de sensores conectados a um ESP32 em tempo real. Utiliza o Thinger.io para visualização em uma dashboard online, permitindo acompanhar medições de temperatura, voltagem, amperagem, potência elétrica, resistência e energia consumida. É uma solução simples e eficaz para aprendizado e prototipagem de sistemas IoT.

## Integrantes do Projeto
- **Ronald de Oliveira Farias** - RM 552364  
- **Gustavo Carvalho Noia** - RM 552466  
- **Vitor Teixeira Silva** - RM 552228  
- **Lucas Serbato de Barros** - RM 551821  
- **Phablo Isaias Santos** - RM 550687  

## Link para a Dashboard e projeto 
Acesse os dados do projeto na dashboard pública:  
[Dashboard Pública no Thinger.io](https://console.thinger.io/dashboards/Dispositivo1?authorization=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJqdGkiOiJEYXNoYm9hcmRfRGlzcG9zaXRpdm8xIiwic3ZyIjoidXMtZWFzdC5hd3MudGhpbmdlci5pbyIsInVzciI6InNlcmJhdG8ifQ.tiw8-6c05XTsL8r6S_v1ruGC4H2W6bUfaaM7FffeCzc)
[Projeto no Wokwi](https://wokwi.com/projects/415028598213747713)

## Dependências Utilizadas
As seguintes bibliotecas e ferramentas são necessárias para o funcionamento do projeto:

- **ThingerESP32**: Para integração do ESP32 com o Thinger.io.
- **DHT Sensor Library**: Para leitura dos sensores de temperatura DHT22.
- **Arduino IDE**: Para desenvolvimento e upload do código.

## Dispositivos Utilizados
- **ESP32 DevKit**: Microcontrolador para leitura dos sensores e envio dos dados.
- **DHT22 (2 unidades)**: Sensores de temperatura e umidade.
- **Potenciômetros (2 unidades)**: Simulam a leitura analógica de voltagem.
- **Resistores de 10kΩ (2 unidades)**: Utilizados como pull-up para os sensores DHT22.
- **LED Vermelho (1 unidade)**: Indicador visual para o projeto.

## Estrutura do Projeto
O sistema coleta dados dos sensores conectados ao ESP32, realiza cálculos e envia os resultados para o Thinger.io. Os dados monitorados incluem:

- **Temperatura (°C)**: Obtida pelos sensores DHT22.
- **Voltagem (V)**: Leitura simulada pelos potenciômetros.
- **Amperagem (A)**: Calculada com base na voltagem lida.
- **Potência (W)**: Calculada como \( P = V \times I \).
- **Resistência (Ω)**: Calculada como \( R = \frac{V}{I} \).
- **Energia (Wh)**: Calculada como \( E = P \times \text{tempo} \).

## Instruções para Replicar e Testar

### Requisitos

#### Hardware
- ESP32 DevKit.
- 2 Sensores DHT22.
- 2 Potenciômetros.
- 2 Resistores de 10kΩ.
- LED vermelho.

#### Software
- Arduino IDE.
- Bibliotecas **ThingerESP32** e **DHT** instaladas.

### Passo a Passo

#### Montagem do Circuito
1. Conecte o **VCC** dos sensores DHT22 ao **3.3V** do ESP32.
2. Conecte o **GND** dos sensores DHT22 ao **GND** do ESP32.
3. Conecte o **SDA** do primeiro DHT22 ao pino **26** do ESP32.
4. Conecte o **SDA** do segundo DHT22 ao pino **27** do ESP32.
5. Adicione resistores de **10kΩ** entre **VCC** e **SDA** de ambos os sensores.
6. Conecte os potenciômetros ao **3.3V**, **GND** e aos pinos **34** e **35** do ESP32.
7. Conecte o LED vermelho ao pino **25** e ao **GND**.

#### Configuração do Código
1. Copie o código fornecido para a IDE Arduino.
2. Instale as bibliotecas **ThingerESP32** e **DHT**.
3. Configure sua rede Wi-Fi nos defines `SSID` e `SSID_PASSWORD`.

#### Upload do Código
1. Selecione a porta e a placa correta na IDE Arduino.
2. Faça o upload do código para o ESP32.

#### Acesso à Dashboard
1. Abra o link da dashboard pública no Thinger.io para visualizar os dados.
2. A dashboard exibe as informações de temperatura, voltagem, amperagem, potência, resistência e energia consumida.

## Funcionamento Esperado
Após a configuração e execução, o sistema deverá:
1. Ler dados dos sensores de temperatura (DHT22).
2. Simular leituras de voltagem utilizando os potenciômetros.
3. Realizar cálculos de amperagem, potência elétrica, resistência e energia consumida.
4. Enviar todos os dados ao Thinger.io em tempo real.
5. Exibir as medições e cálculos no console da IDE Arduino.

## Observações
Caso encontre dúvidas ou dificuldades, o sistema pode ser facilmente ajustado para atender às suas demandas. Este projeto é modular e aberto a novas funcionalidades.
