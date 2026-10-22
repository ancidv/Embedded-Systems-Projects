#define LDR_PIN 34
#define LED_PIN 2

int threshold = 2000;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    int lightValue = analogRead(LDR_PIN);

    Serial.print("Light value: ");
    Serial.println(lightValue);

    if(lightValue < threshold)
    {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Street Light ON");
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
        Serial.println("Street Light OFF");
    }

    delay(500);
}
