/**
 * @autor Laura Jimena Pinzon Gamboa
 */

const int ledPin = 13;  // LED integrado en Arduino Uno

/**
 * Inicializa la comunicación serie y configura el pin del LED.
 */
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("Calculadora");
}

/**
 * Parpadea el LED integrado un número específico de veces.
 * Cada flash consiste en encender el LED por 500 ms y apagarlo por 500 ms.
 * flashes Número de flashes a realizar.
 */
void flashLED(int flashes) {
  for (int i = 0; i < flashes; i++) {
    digitalWrite(ledPin, HIGH);  // Enciende LED
    delay(500);                  // Espera 1000 ms
    digitalWrite(ledPin, LOW);   // Apaga LED
    delay(500);                  // Espera 1000 ms
  }
}

/**
 * Muestra el menú de operaciones en la consola serie.
 */
void mostrarMenu() {
  Serial.println("\nSeleccione la operación:");
  Serial.println("1=Suma ");
  Serial.println("2=Resta ");
  Serial.println("3=Multiplicación ");
  Serial.println("4=División");
  Serial.print("Opción: ");
}

/**
 * Lee un número entero desde la consola serie.
 * Número entero ingresado.
 */
int leerEntero() {
  while (Serial.available() == 0) {
    // Espera a que el usuario ingrese un dato
  }
  int valor = Serial.parseInt();
  Serial.read(); // Limpiar buffer
  return valor;
}

/**
 * Función principal que ejecuta el programa.
 */
void loop() {
  mostrarMenu();

  // Esperar opción válida
  while (Serial.available() == 0) {
    // Espera
  }
  int opcion = Serial.parseInt();
  Serial.read(); // Limpiar buffer

  if (opcion < 1 || opcion > 4) {
    Serial.println("Opción inválida. Intente de nuevo.");
    return;
  }

  Serial.print("Ingrese el primer operando: ");
  int op1 = leerEntero();
  Serial.println(op1);

  Serial.print("Ingrese el segundo operando: ");
  int op2 = leerEntero();
  Serial.println(op2);

  int resultado = 0;
  bool divisionValida = true;

  switch (opcion) {
    case 1: // Suma
      resultado = op1 + op2;
      Serial.print("Resultado: ");
      break;
    case 2: // Resta
      resultado = op1 - op2;
      Serial.print("Resultado: ");
      break;
    case 3: // Multiplicación
      resultado = op1 * op2;
      Serial.print("Resultado : ");
      break;
    case 4: // División
      if (op2 == 0) {
        Serial.println("Error: División por cero no permitida.");
        divisionValida = false;
      } else {
        resultado = op1 / op2;  // División entera
        Serial.print("Resultado : ");
      }
      break;
  }

  if (divisionValida) {
    Serial.println(resultado);

    // Señalización con LED según resultado
    if (resultado > 0) {
      flashLED(1);  // Un flash para resultado positivo
    } else if (resultado < 0) {
      flashLED(2);  // Dos flashes para resultado negativo
    } else {
      flashLED(3);  // Tres flashes para resultado cero
    }
  }
}
