
// settings
#define FPS 50
#define FADELENGTH 5
#define RPIN 9
#define GPIN 10
#define BPIN 11
#define GROUND 12

int rVal = 0;
int gVal = 0;
int bVal = 0;

const int STEPS = FPS * FADELENGTH;
const int WAIT = 1000 / FPS;

void transis2color(int nr, int ng, int nb){

    int delR = nr - rVal;
    int delG = ng - gVal;
    int delB = nb - bVal;

    double stpR = (double)delR / STEPS;
    double stpG = (double)delG / STEPS;
    double stpB = (double)delB / STEPS;

    for(int i=1; i<=STEPS; i++){
        analogWrite(RPIN, rVal + stpR * i);
        analogWrite(GPIN, gVal + stpG * i);
        analogWrite(BPIN, bVal + stpB * i);
        delay(WAIT);
    }

    analogWrite(RPIN, nr);
    analogWrite(GPIN, ng);
    analogWrite(BPIN, nb);

    rVal = nr;
    gVal = ng;
    bVal = nb;

}

void setup(){
    pinMode(GROUND, OUTPUT);
    digitalWrite(GROUND, LOW);
}

void loop(){

    int rArr[] = {255,255,255,255,255,191,128,64,0,0,0,0,0,0,0,0,0,64,128,191,255,255,255,255,255};
    int gArr[] = {0,64,128,191,255,255,255,255,255,255,255,255,255,191,128,64,0,0,0,0,0,0,0,0,0};
    int bArr[] = {0,0,0,0,0,0,0,0,0,64,128,191,255,255,255,255,255,255,255,255,255,191,128,64,0};

    for(int i=0; i < 25; i++){
        transis2color(rArr[i], gArr[i], bArr[i]);
    }
}
