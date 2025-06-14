// Pin tanımları
int A_kirmizi = 2;
int A_sari    = 3;
int A_yesil   = 4;

int B_kirmizi = 5;
int B_sari    = 6;
int B_yesil   = 7;

int Y_kirmizi = 8;
int Y_yesil   = 9;

int yaya_buton = 10;

// Buton durumu
bool butona_basildi_mi = false;

void setup() {
  pinMode(A_kirmizi, OUTPUT);
  pinMode(A_sari, OUTPUT);
  pinMode(A_yesil, OUTPUT);

  pinMode(B_kirmizi, OUTPUT);
  pinMode(B_sari, OUTPUT);
  pinMode(B_yesil, OUTPUT);

  pinMode(Y_kirmizi, OUTPUT);
  pinMode(Y_yesil, OUTPUT);

  pinMode(yaya_buton, INPUT_PULLUP); // Dahili pull-up direnci kullanıyoruz
}

void loop() {
  // --- Buton kontrolü ---
  if (digitalRead(yaya_buton) == LOW) {
    butona_basildi_mi = true;
  }

  // --- A Yönü Yeşil ---
  digitalWrite(A_yesil, HIGH);
  digitalWrite(A_kirmizi, LOW);
  digitalWrite(A_sari, LOW);

  digitalWrite(B_kirmizi, HIGH);
  digitalWrite(B_yesil, LOW);
  digitalWrite(B_sari, LOW);

  digitalWrite(Y_kirmizi, HIGH);
  digitalWrite(Y_yesil, LOW);

  delay(10000); // A yeşil

  // --- A Sarı ---
  digitalWrite(A_yesil, LOW);
  digitalWrite(A_sari, HIGH);
  delay(3000);
  digitalWrite(A_sari, LOW);
  digitalWrite(A_kirmizi, HIGH);

  // --- Yaya Geçidi Kontrolü ---
  if (butona_basildi_mi) {
    digitalWrite(Y_kirmizi, LOW);
    digitalWrite(Y_yesil, HIGH);
    delay(5000);
    digitalWrite(Y_yesil, LOW);
    digitalWrite(Y_kirmizi, HIGH);
    butona_basildi_mi = false; // buton sıfırlanır
  }

  // --- B Yönü Yeşil ---
  digitalWrite(B_kirmizi, LOW);
  digitalWrite(B_yesil, HIGH);
  delay(10000);

  // --- B Sarı ---
  digitalWrite(B_yesil, LOW);
  digitalWrite(B_sari, HIGH);
  delay(3000);
  digitalWrite(B_sari, LOW);
  digitalWrite(B_kirmizi, HIGH);

  // --- Yaya Geçidi Kontrolü (tekrar) ---
  if (butona_basildi_mi) {
    digitalWrite(Y_kirmizi, LOW);
    digitalWrite(Y_yesil, HIGH);
    delay(5000);
    digitalWrite(Y_yesil, LOW);
    digitalWrite(Y_kirmizi, HIGH);
    butona_basildi_mi = false;
  }
}
