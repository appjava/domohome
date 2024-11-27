# Proyecto Domótica - Control y Monitoreo de Hogar

Este proyecto implementa un sistema de domótica utilizando una placa de desarrollo Wemos D1 (ESP8266) para controlar luces, sensar temperatura y humedad, y monitorear el sistema de almacenamiento de energía. La interfaz de usuario está basada en web y permite controlar y visualizar el estado del sistema de forma local mediante una conexión WiFi.

## Características
- **Control de luces**: Permite encender y apagar luces de manera remota.
- **Sensado de temperatura y humedad**: Muestra en tiempo real la temperatura y humedad de las diferentes habitaciones o zonas.
- **Monitoreo de energía**: Monitoreo del sistema de almacenamiento de energía (baterías, paneles solares, etc.).
- **Interfaz web local**: Control y visualización de datos mediante una interfaz web accesible dentro de la red WiFi.
- **Notificaciones y alertas**: Configuración de alertas para cambios significativos en temperatura, humedad o niveles de energía.

## Hardware
- **Placa de desarrollo**: Wemos D1 (ESP8266)
- **Sensores**:
  - DHT22 para temperatura y humedad.
  - [Agregar aquí otros sensores o módulos específicos, como sensores de corriente o voltaje, si es necesario].
- **Otros**: Relés para el control de luces, módulo de monitoreo de energía, etc.

## Software
El software está basado en el entorno de desarrollo **Arduino IDE** y utiliza la librería ESP8266 para la comunicación a través de WiFi.

- **Lenguaje**: C/C++
- **Librerías**:
  - ESP8266WiFi
  - DHT (para el sensor de temperatura y humedad)
  - [Agregar otras librerías que estés utilizando]
  
## Instalación
1. Clona este repositorio.
2. Abre el proyecto en el **Arduino IDE**.
3. Asegúrate de tener instalada la placa **Wemos D1 (ESP8266)** en tu entorno de desarrollo.
4. Configura tu red WiFi en el código (modifica el archivo `config.h` para poner tu SSID y contraseña).
5. Conecta los sensores a los pines correspondientes de la placa.
6. Carga el código a tu placa Wemos D1 utilizando el IDE de Arduino.

## Uso
1. Conecta el dispositivo a tu red WiFi.
2. Accede a la interfaz web abriendo el navegador y escribiendo la dirección IP del Wemos D1 en la barra de direcciones (puedes encontrar la IP en el monitor serie del IDE de Arduino).
3. Controla las luces, visualiza los datos de temperatura y humedad, y monitorea el sistema de almacenamiento de energía desde la interfaz web.

## Contribuciones
Las contribuciones son bienvenidas. Si deseas mejorar el proyecto o añadir nuevas características, por favor realiza un fork y abre un pull request.

## Licencia
Este proyecto está bajo la Licencia MIT - consulta el archivo [LICENSE](LICENSE) para más detalles.
