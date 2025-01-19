## Aprendiendo y compartiendo circuitos con Arduino con mi hijo

## Como montarlo

1. Descargar el AppImage de: https://www.arduino.cc/en/software
2. Hacer el archivo ejecutable y abrirlo
3. Conectar la placa por usb
4. Añadir mi usuario al grupo `dialout` (estoy utilizando Linux Mint): `sudo usermod -a -G dialout $USER`
   * Alternativamente, buscar el punto de montaje y darle permisos: `sudo chmod a+rw /dev/ttyACM0`.
