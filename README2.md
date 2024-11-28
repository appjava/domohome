# Proyecto de Domótica

![Banner de inicio](cover.png)

**Descripción**: Este proyecto utiliza una **placa Wemos D1** con **ESP8266** para controlar luces, medir temperatura y humedad, y monitorear energía. La interfaz de usuario es accesible localmente a través de una página web usando WiFi.

---

## 🚀 Características

- **Control de luces**: Enciende y apaga luces remotamente.
- **Sensado de temperatura y humedad**: Medido por el sensor **DHT22**.
- **Monitoreo de corriente y voltaje**: Usando los sensores **ACS712** para corriente y **FZ0430** para voltaje.
- **Interfaz web**: Accesible a través de Wi-Fi.

---

## 📦 Requisitos de Hardware

| Componente      | Descripción            |
|-----------------|------------------------|
| **Wemos D1**    | Placa base ESP8266     |
| **DHT22**       | Sensor de temperatura y humedad |
| **ACS712**      | Sensor de corriente    |
| **FZ0430**      | Sensor de voltaje      |
| **Fuente de alimentación** | Para el ESP8266 y sensores |

---

## 📂 Instalación

1. **Clona el repositorio**:
   ```bash
   git clone https://github.com/tu-usuario/tu-repositorio.git

### 2. Abre el Proyecto en el IDE de Arduino

- Asegúrate de que tienes instalada la **placa Wemos D1** en el IDE de Arduino.
- Descarga e instala las siguientes bibliotecas desde el **Gestor de Bibliotecas** del IDE de Arduino:
  - `ESP8266WiFi`
  - `ESP8266HTTPClient`
  - `SimpleDHT`
  - `ACS712`
  - `ESPAsyncWebServer`
  - `ArduinoJson`

### 3. Subir el Código al ESP8266

- Conecta tu **Wemos D1** a tu computadora.
- Selecciona el puerto y la placa correcta en el IDE de Arduino.
- Haz clic en el botón **Subir** para cargar el código en la placa.

### 4. Conéctate a la Interfaz Web

- Una vez que el dispositivo se conecte a tu red Wi-Fi, abre el **Monitor Serie** en el IDE de Arduino para obtener la dirección IP local del dispositivo.
- Accede a la interfaz web desde cualquier navegador usando la IP proporcionada.

---

## 📑 Enlaces Útiles

- [Repositorio en GitHub](https://github.com/tu-usuario/tu-repositorio)
- [Documentación del sensor DHT22](https://www.example.com/dht22-doc)
- [Guía de instalación de Wemos D1](https://www.example.com/wemos-d1-guide)

---

## 🔧 Dependencias

Para que este proyecto funcione correctamente, necesitarás las siguientes bibliotecas:

- `ESP8266WiFi.h`
- `ESP8266HTTPClient.h`
- `SimpleDHT.h`
- `ACS712.h`
- `ESPAsyncWebServer.h`
- `ArduinoJson.h`

Puedes instalarlas fácilmente desde el **Gestor de Bibliotecas** de Arduino.

---

## 💡 Contribuciones

¡Las contribuciones son bienvenidas! Si deseas contribuir a este proyecto, por favor sigue estos pasos:

1. Haz un **fork** del repositorio.
2. Crea una nueva rama (`git checkout -b feature/nueva-funcionalidad`).
3. Realiza tus cambios y asegúrate de que el código esté bien probado.
4. Haz un **commit** de tus cambios (`git commit -am 'Agrega nueva funcionalidad'`).
5. Sube tus cambios a tu repositorio (`git push origin feature/nueva-funcionalidad`).
6. Abre un **pull request** con una descripción detallada de lo que has modificado.

Si encuentras algún problema o tienes alguna sugerencia, no dudes en abrir un **issue**.

Gracias por contribuir a mejorar este proyecto.

---

## 📝 Licencia

Este proyecto está bajo la **Licencia MIT**. Puedes ver más detalles en el archivo [LICENSE](LICENSE).

La Licencia MIT es una licencia de software de código abierto que permite a cualquier persona usar, copiar, modificar y distribuir el software, con la condición de que se incluya una copia del aviso de la licencia en las distribuciones del software.

---

## 🚧 Estado del Proyecto

Este proyecto está en fase **beta**. Actualmente estamos trabajando en las siguientes mejoras:
- Mejorar la interfaz web.
- Optimizar la eficiencia energética.
- Integrar nuevos sensores y dispositivos.

Si tienes alguna sugerencia, ¡no dudes en contribuir!

---

## 🌟 Frase Inspiradora

> "La gente que está lo suficientemente loca como para pensar que puede cambiar el mundo, es la que lo hace."  
> — **Steve Jobs**
>

---

# Proyecto de Domótica con ESP8266

![Build Status](https://img.shields.io/travis/appjava/domohome.svg)
![Version](https://img.shields.io/github/v/release/appjava/domohomo.svg)

## 🚀 Estado del Proyecto

Este proyecto está en fase **beta**. Actualmente estamos trabajando en las siguientes mejoras:
- Mejorar la interfaz web.
- Optimizar la eficiencia energética.
- Integrar nuevos sensores y dispositivos.

Si tienes alguna sugerencia, ¡no dudes en contribuir!

