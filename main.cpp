#include <iostream>
#include <iomanip>
using namespace std;

// Clasifica un char: 'v' vocal, 'c' consonante, 'f' no es letra
char indentificar_letra(char l){
    if ( ( l>=65 && l<=90)|| (l>=97 && l<=122) ) { // rango ASCII de letras mayus/minus
        if  (l=='a'||l=='e'||l=='i'||l=='o'||l=='u'||l=='A'||l=='E'||l=='I'||l=='O'||l=='U'){
            return 'v';
        }
        else{
            return 'c';
        }
    }
    return 'f';

}

void problema_1(){
    char a,l;
    cout<<"Ingrese una letra para comprobar si es consonante, vocal o ninguna: "<<endl;
    cin>>a;
    l= indentificar_letra(a);

    if (l=='f'){
        cout<<"No es una letra"<<endl;
    }
    else if (l=='v'){
        cout<<"es una vocal"<<endl;
    }
    else if (l=='c'){
        cout<<"es una consonante"<<endl;
    }
}

// Valida si el dia 'd' existe dentro del mes 'm' (usa 29 fijo para febrero)
bool dia_mes(int m,int d){
    switch(m){
    case 2:
        if (d>=1 && d<=29){
            return true;
        }
        else{
            return false;
        }
    case 4:
    case 6:
    case 9:
    case 11:
        if (d>=1&&d<=30){
            return true;
        }
        else{
            return false;
        }
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (d>=1&&d<=31){
            return true;
        }
        else{
            return false;
        }
    default:
        return false;
    }


}

void problema_3(){
    int m,d;
    cout<<"Ingrese un mes"<<endl;
    cin>>m;
    cout<<"Ingrese un dia"<<endl;
    cin>>d;
    if (dia_mes( m,d)){
        if (m==2&&d==29){
            cout<<d<<"/"<<m<<" es valido en bisiesto"<< endl;
        }
        else{
            cout<<d<<"/"<<m<<" es una fecha valida"<< endl;
        }
    }
    else{
        if ((m<1)||(m>12)){
            cout<<m<<" no es un mes valido"<< endl;

        }
        else{
            cout<<d<<"/"<<m<<"no es una fecha valida"<< endl;
        }
    }

}

// Dibuja un rombo de asteriscos de ancho n (n debe ser impar): primero la mitad de arriba, luego la de abajo
void figura(int n){
    int es=(n-1)/2; // cantidad de espacios iniciales
    for (int i=0;i<=n;i+=2){
        for (int e=0;e<=i+es;e+=1){
            if (e>es-1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        es-=1;
        cout<<endl;
    }
    es=1;
    for (int i=n-2;i>0;i-=2){
        for (int e=0;e<i+es;e+=1){
            if (e>=es){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        es+=1;
        cout<<endl;
    }


}

void problema_5(){
    int n;
    cout<<"Ingrese un numero entero impar para el patron: "<<endl;
    cin>>n;
    figura(n);
}

// Suma los terminos PARES de Fibonacci menores que n
int fobonacci(int n){
    int a=1, b=0,e,cont=0;

    while(a<n){
        if (a%2==0){
            cont+=a;
        }
        e=a;
        a=a+b; // siguiente termino de fibonacci
        b=e;
    }
    return cont;

}

void problema_7(){
    int n,rest;
    cout<<"Ingrese un numero para calcular los pares de fibonacci hasta ese numero: "<<endl;
    cin>>n;
    rest = fobonacci( n);
    cout<<"El resultado de la suma es: "<<rest<<endl;
}

// Suma cada digito de n elevado a si mismo (digito^digito) y acumula
int suma_num(int n){
    int rest,cont=0,tem;
    while (n>=1){
        rest= n%10; // ultimo digito
        tem=rest;
        for (int e=1;e<tem;e+=1){
            rest*=tem; // eleva el digito a su propia potencia
        }
        cont+=rest;
        n/=10;
    }
    return cont;


}

void problema_9(){
    int n,rest;
    cout<<"Ingrese un numero para saber la suma de sus digitos: "<<endl;
    cin>>n;
    rest= suma_num(n);
    cout<<"El resultado de la suma es: "<<rest<<endl;

}

// Busca, a partir de n, el numero cuya cantidad de divisores es igual a n (o sea, el mcm 1..n)
int mcd(int n){
    int cont=n , cunt;
    while(true){
        cunt=1; // cuenta divisores de "cont"
        for (int i=2;i<=n;i+=1){
            if (cont%i==0){
                cunt+=1;
            }
            else{
                cont+=1; // si no es divisible por algun i, prueba el siguiente numero
                break;
            }
        }
        if (cunt==n){
            return cont;
        }

    }
}

void problema_11(){
    int n, res ;
    cout<<"Ingrese un numero para calcular el mcm de todos los numeros enteros entre 1 y el numero ingresado."<<endl;
    cin>>n;
    res= mcd( n);
    cout<<"El minimo comun multiplo es: "<<res<<endl;
}

// Prueba de primalidad por division (O(n),
bool es_primo(int n){
    for (int i=2;i<n;i+=1){
        if(n%i==0){
            return false;
        }
    }
    return true;

}
void problema_13(){
    int n,cont=0;
    cout<<"Ingrese un numero para calcular la suma de los primos menores que el: "<<endl;
    cin>>n;
    for(int i=2;i<n; i+=1){
        if(es_primo(i)){
            cont+=i;
        }
    }
    cout<<"El resultado de la suma es: "<< cont<<endl;

}



// Suma los numeros de la diagonal de una espiral cuadrada de lado n (recorre anillo por anillo)
int espiral(int n){
    if (n == 1) {
        return 1;
    }
    int cunt=(n*n)+(-n+1), cont=n*n,nus=n-1 ;
    while(true){
        for (int i=1;i<=4;i+=1){ // los 4 vertices del anillo actual
            cont+=cunt;
            if((i+1<=4)){
                cunt-=nus;
            }
            else{
                nus-=2; // pasa al siguiente anillo (mas interno)
                cunt-=nus;
            }
        }
        if (cunt<=1){
            return cont;
        }
    }
}

// Valor absoluto manual
int abs_manual(int x){
    if (x < 0) return -x;
    return x;
}

int valorCelda(int fila, int col, int n){
    int c = n/2;                        // indice del centro
    int df = fila - c;              // distancia de la fila al centro (negativo = arriba, positivo = abajo)
    int dc = col - c;               // distancia de la columna al centro (negativo = izquierda, positivo = derecha)

    int anillo = abs_manual(df);        // anillo = capa a la que pertenece

    if (abs_manual(dc) > anillo) {
        anillo = abs_manual(dc);        // anillo = max(|df|,|dc|)
    }

    if (anillo == 0) {
        return 1;                       // caso especial: el centro
    }

    int ladoAnillo = 2*anillo;          // numeros por lado del anillo

    int primerDelAnillo = (2*anillo - 1)*(2*anillo - 1) + 1;  // primer numero del anillo

    if (dc == anillo && df > -anillo && df < anillo){         // ¿lado derecho?
        int offset = df + anillo - 1;   // avance dentro del lado derecho
        return primerDelAnillo + offset;
    }

    if (df == anillo && dc <= anillo && dc > -anillo){        // ¿lado de abajo?
        int offset = ladoAnillo + (anillo - dc) - 1;          // +1 lado ya recorrido
        return primerDelAnillo + offset;
    }

    if (dc == -anillo && df <= anillo && df > -anillo){       // ¿lado izquierdo?
        int offset = 2*ladoAnillo + (anillo - df) - 1;        // +2 lados ya recorridos
        return primerDelAnillo + offset;
    }

    int offset = 3*ladoAnillo + (anillo + dc) - 1;            // lado de arriba (por descarte)
    return primerDelAnillo + offset;                          // +3 lados ya recorridos
}

void imprimir_espiral(int n){
    for (int fila = 0; fila < n; fila++){       // recorre filas
        for (int col = 0; col < n; col++){      // recorre columnas
            cout << setw(4) << valorCelda(fila, col, n);   // calcula e imprime, ancho fijo
        }
        cout << endl;                           // salto de linea por fila
    }
}

void problema_15(){
    int n,rest;
    cout<<" Escriba un numero impar para calcular la suma de los numeros en la diagonal"<< endl;
    cin>>n;
    rest =espiral(n);
    cout<<"La suma de su diagonal es: "<<rest<<endl;
    imprimir_espiral(n);
}
// Busca el primer numero triangular (1, 3, 6, 10...) con mas divisores que n
void triangular(int n, int list[]){
    int divi=0,pos=0,num;
    while(divi<=n){
        divi=1;
        pos+=1;
        num=(pos*(pos+1)/2); // formula del numero triangular
        for(int i=2;i<=num;i+=1){
            if (num%i==0){
                divi+=1;
            }
        }
    }
    list[0]=num;   // numero triangular encontrado
    list[1]=divi;  // su cantidad de divisores

}

void problema_17(){
    int n;
    int list[2];
    cout<<"Ingrese un numero para saber cual es el primer numero triangular que tiene mas divisores que su numero: "<<endl;
    cin>>n;
    triangular( n,list);
    cout<<"El numero es: "<<list[0]<< " que tiene: "<<list[1]<<" divisores"<<endl;

}


// Menu principal: enruta al problema segun el numero ingresado
int main(){
    int x;
    while(true){
        cout<<"Ingrese el numero de un problema o ingrese 18 para salir : "<<endl;
        cin>>x;
        switch (x) {
        case 1:
            problema_1();
            break;
        case 3:
            problema_3();
            break;
        case 5:
            problema_5();
            break;
        case 7:
            problema_7();
            break;
        case 9:
            problema_9();
            break;
        case 11:
            problema_11();
            break;
        case 13:
            problema_13();
            break;
        case 15:
            problema_15();
            break;
        case 17:
            problema_17();
            break;
        case 18:
            return 0;
        default:
            cout<<"Numero incorrecto"<<endl;
            break;
        }

    }
}
