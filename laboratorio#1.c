#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<conio.h>
//#include<string.h>
int t=0;
struct conj
{
    char elementos[10];
}conjuntos[0];

void menu();
void crear();
void insertar();
void operaciones();
int conj_universal(int);
void imprimir();
int cardinales();
void conj_potencia(int);
int verificar(int,int);
void inicializar();
int repetido(int,int);
void uniontalves(int,int,int,int);
void disjuntotalvez(int,int,int,int);
void diferencia_simtalves(int,int,int,int);
void sub_conjuntotalves(int,int,int,int);

void main(){

    inicializar();
    menu();
}

void inicializar(){
    for(int i=0;i<10;i++){
        conjuntos[0].elementos[i]=0;
    }
    printf(" Para Iniciar Tiene Un Conjunto Vacio \n");
    system("pause");
}

void menu(){
    int i=0,desicion=0;
        system("cls");
        printf("1: crear un nuevo conjunto\n");
        printf("2: insertar a un conjunto ya creado\n");
        printf("3: operaciones\n");
        printf("4: salir\n");
        fflush(stdin);
        i=scanf("%i",&desicion);
        if(i==1 && desicion>0){
            switch (desicion)
            {
                case 1:{
                    crear();
                    break;
                }
                case 2:{
                    insertar();
                    break;
                }
                case 3:{
                    operaciones();
                    break;
                }

                case 4:{
                    return;
                }
            }
        }else{
            printf("\nvalor invalido\n");
        }
    menu();
}

void crear(){
    int s=0,queda=0,ac=0,anterior=0;
    if(t==5){
        printf("alcanzo el maximo de conjuntos");
        return;
    }else{
        queda = 5-t;
        do{
             printf("cuantos conjuntos utilizara, no mayor a %d : ",queda);
             fflush(stdin);
             s=scanf("%d",&ac);
             if(s==1 || ac>0){ //valida que es un numero
                 if(ac<queda){
                     t = t+ac;
                     conjuntos[t];
                     insertar();
                   }else{
                     printf("el valor se excede");
                    }
              }else{
                 printf("opcion no valida");
              }
          }while(s!=1 && (ac<queda));
    }
    return;
}

void insertar(){
    char a,d; int ve=0,x=0,i=0,usado=0,nelem=0,e=0;
    printf("\n Tiene %d Conjuntos --- Elija el conjunto a usar: ",t+1);
    fflush(stdin);
    x=scanf("%i",&e);
    e--;
    ve=verificar(x,e);
    if(ve==1){
       //evaluar que el conjunto tiene datos------
        for(i=0;i<10;i++){
            if(conjuntos[e].elementos[i]!=0){
                 usado++;
            }
        }
        if(usado==9){
            printf(" El conjunto %d esta lleno ",e+1);
            return;
        }else{
            printf("tiene %d datos",usado);
            nelem = usado;
            //insertar-----------
         do{
           if(nelem<=8){
              int s=0;
              fflush(stdin);
              printf("\n Inserte el elemento: ");
              a=getchar();
              for(i=0;i<(nelem+1);i++){
                 if(a==conjuntos[e].elementos[i]){
                     s=1;
                 }
               }
               if(s==0){
                   conjuntos[e].elementos[nelem+1]=a;
                   nelem++;
               }
               fflush(stdin);
               printf("\n s Para agregar otro elemento: ");
               scanf("%c",&d);
            }else{
                printf("\nel conjunto esta lleno\n");
                system("pause");
                return;
           }
        }while(d==115);
      }

    }else{
        printf("\nlos numeros van desde el 1 hasta el %d\n",t+1);
        system("pause");
        insertar();
    }
    return;
}

void imprimir(){
    int i=0,s=0,tam=0,x=0;
    for(s=0;s<=t;s++){
        for(i=0;i<10;i++){
            if(conjuntos[s].elementos[i]!=0){
                tam++;
            }
        }
        printf("\nCONJUNTO %d:\n",s+1);
        for(x=0;x<=tam;x++){
            printf(" %d: [%c]",x,conjuntos[s].elementos[x]);
        }
        tam=0;
    }
}

void operaciones(){
    int desicion=0, i=0,car=0,c_universal=7;
    do{
        system("cls");
        imprimir();
        printf("\n\n****OPERACIONES DE CONJUNTOS***");
        printf("\n1:Escoger Universal");
        printf("\n2:Subconjutos");
        printf("\n3:Cardinalidad");
        printf("\n4:Conjunto Potencia");
        printf("\n5:Conjunto Disjunto y Conjunto Interseccion");
        printf("\n6:Union");
        printf("\n7:Diferencia Simetrica y Complemento Relativo");
        printf("\n8:Volver\n");
        fflush(stdin);
        i=scanf("%d", &desicion);
        if(i!=1){
            printf("valor invalido");
            system("pause");
        }else{
            if((desicion>=1) && (desicion<=8)){
                switch(desicion){
                    case 1:{
                            c_universal=conj_universal(c_universal);
                            break;
                        }
                    case 2:{
                        c_universal=repetido(4,c_universal);
                            break;
                        }
                    case 3:{
                        car = cardinales();
                            break;
                        }
                    case 4:{
                        conj_potencia(car);
                            break;
                        }
                    case 5:{
                        c_universal=repetido(1,c_universal);
                        break;
                    }
                    case 6:{
                        c_universal=repetido(2,c_universal);
                        break;
                    }
                    case 7:{
                        c_universal=repetido(3,c_universal);
                        break;
                    }
                    case 8:{
                        return;
                    }
                }
            }else{
                printf("\nvalor invalido");
                system("pause");
            }
        }
    }while(i!=3);
}

int conj_universal(int c_universal){
    int s=0, i=0,ve=0; char x;
    system("cls");
    if(c_universal!=7){
        fflush(stdin);
        printf("Usted ya tiene un conjunto UNIVERSAL %d\n",c_universal);
        printf("si desea cambiarlo oprima s\n");
        scanf("%c",&x);
        if(x!=115){
            return c_universal;
        }
    }
    imprimir();
    do{
        fflush(stdin);
        printf("\nElija un conjunto Universal: ");
        s=scanf("%d", &c_universal);
        c_universal--;
        ve=verificar(s,c_universal);
        if(ve==1){
            printf("\nEl conjunto universal es: ");
                for(i=0;i<10;i++){
                    printf("  [%c]",conjuntos[c_universal].elementos[i]);
                }
                printf("\n");system("pause");
        }else{
            printf("\nEse conjunto no existe\n");
            system("pause");
            ve=0;
        }
  }while(ve!=1);
  return c_universal;
}

void sub_conjuntotalves(int e, int a, int a2,int c_universal){
    int i=0,f=0,repite=0;
    for(i=0; i<a2; i++){
        for(f=0; f<a; f++){
            if(conjuntos[c_universal].elementos[i]==conjuntos[e].elementos[f]){
                repite++;
             }
         }
      }
      if(repite==a && repite==a2){
          printf("\nEl Conjunto %d es Subconjunto del Universal\n", e+1);
          system("pause");
       }else{
           if(repite==a && repite<a2){
                 printf("\nEl Conjunto %d es Subconjunto propio del Universal\n", e+1);
                 system("pause");
           }else{
              if(repite<a){
                  printf("\nEl Conjunto %d no es Subconjunto del Universal\n", e+1);
                  system("pause");
              }
           }
        }
}

int cardinales(){
    int x=0,i=0,car=0,e=0;
        system("cls");
        imprimir();
        fflush(stdin);
        printf("\n\nElija el conjunto\n");
        x=scanf("%i",&e);
        e--;
       if((x==1) && (e>=0 && e<=t)){
                for(i=0;i<10;i++){
                    if(conjuntos[e].elementos[i]!=0){
                        car++;
                    }else{
                        continue;
                    }
                }
                printf("la cardinal es 2^(%d)\n",car);
                system("pause");
        }else{
                printf("\nvalor invalido\n");
                system("pause");
                cardinales();
                return car-1;
            }
}

void conj_potencia(int car){
   car=cardinales();
   printf("aun nada");
}

int repetido(int cual,int c_universal){
    int bucle=0;
    do{ bucle=0;
        int a=0,a2=0, x=0,i=0,e=0,ve=0;
        if(c_universal==7){
            printf("\n Debe elegir un conjunto universal primero\n");
            system("pause");
            c_universal=conj_universal(c_universal);
        }
            if(t>=1){
                system("cls");
                imprimir();
                fflush(stdin);
                printf("\nEscoja un conjunto entre %d: ",t+1);
                x=scanf(" %d", &e);
                e--;
                ve=verificar(x,e);
                    if((ve!=1) || (e == c_universal)){
                           printf(" ELIJIO EL MISMO CONJUNTO QUE EL UNIVERSAL O NO INSERTO UN VALOR CORRECTO");
                           system("pause");system("cls");
                           bucle=1;
                    }else{
                         for(i=0;i<10;i++){
                                if(conjuntos[e].elementos[i]!=0){
                                    a++;
                                }
                                if(conjuntos[c_universal].elementos[i]!=0){
                                    a2++;
                                }
                            }
                            //INICIA ENVIAR------------------
                                switch(cual){
                                    case 1:{
                                        disjuntotalvez(e,a,a2,c_universal);
                                        break;
                                    }
                                    case 2:{
                                        uniontalves(e,a,a2,c_universal);
                                        break;
                                    }
                                    case 3:{
                                        diferencia_simtalves(e,a,a2,c_universal);
                                        break;
                                    }
                                    case 4:{
                                        sub_conjuntotalves(e,a,a2,c_universal);
                                    }
                                }

                            //FIN ENVIAR--------------------
                    }
        }else{
            printf("Para esta operacion necesita al menos dos conjuntos");
            system("pause");system("cls");
            crear();
            bucle=1;
        }
    }while(bucle==1);
    return c_universal;
}

void diferencia_simtalves(int e,int a, int a2,int c_universal){
    int i=0,f=0,repite=0,d=0,cr=0; char diferencia[20];
   for(i=0;i<20;i++){
      diferencia[i]=0;
    }
    for(i=1; i<=a; i++){
         for(f=1; f<=a2; f++){
              if(conjuntos[e].elementos[i]==conjuntos[c_universal].elementos[f]){
                    repite++;
              }
          }
          if(repite==0){
               diferencia[d]=conjuntos[e].elementos[i];
               d++;  cr++;
           }
           repite=0;
    }
    printf("\nComplemento Relativo %d - %d\n",e+1, c_universal+1);
    for(i=0;i<d;i++){
        printf(" [%c] ",diferencia[i]);
     }
     repite=0;
     for(i=1; i<=a2; i++){            //mismo codigo
        for(f=1; f<=a; f++){
             if(conjuntos[c_universal].elementos[i]==conjuntos[e].elementos[f]){
                  repite++;
              }
        }
        if(repite==0){
           diferencia[d]=conjuntos[c_universal].elementos[i];
           d++;
        }
        repite=0;
    }
    printf("\nComplemento Relativo %d - %d\n",c_universal+1,e+1);
    for(i=cr;i<d;i++){
        printf(" [%c] ",diferencia[i]);
     }                                    //fin mismo codigo
    printf("\ndiferencia simetrica\n");
   for(i=0;i<d;i++){
       printf(" [%c] ",diferencia[i]);
   }printf("\n");system("pause");
}

void disjuntotalvez(int e,int a, int a2, int c_universal){
    int i=0,f=0,repite=0;
    char interseccion[20];
    for(i=1; i<=a; i++){
        for(f=1; f<=a2; f++){
            if(conjuntos[e].elementos[i]==conjuntos[c_universal].elementos[f]){
                interseccion[repite]=conjuntos[e].elementos[i];
                repite++;
            }
        }
    }
    if(repite==0){
        printf("Los Conjuntos son DISJUNTOS\n");
        system("pause");
    }else{
        printf("Los Conjuntos Tienen INTERSECCION\n");
        for(i=0;i<repite;i++){
            printf("[%c]",interseccion[i]);
        }printf("\n");
        system("pause");
    }
}

void uniontalves(int e, int a, int a2,int c_universal){
    char uniones[20];
    int i=0,f=0,u=0,repite=0;
    for(i=0;i<20;i++){
        uniones[i]=0;
    }
    for(i=1; i<=a; i++){
        uniones[u]=conjuntos[e].elementos[i];
        u++;
    }
    for(f=1; f<=a2; f++){
        for(i=0;i<=a;i++){
            if(conjuntos[c_universal].elementos[f]==uniones[i]){
                repite++;
            }
        }
         if(repite==0){
              uniones[u]=conjuntos[c_universal].elementos[f];
              u++;
        }
          repite=0;
    }
    printf("\nla union es:\n");
    for(i=0;i<=u;i++){
        printf(" [%c] ",uniones[i]);
    }printf("\n");
    system("pause");
}

int verificar(int z,int x){
    if(z==1 && ((x>=0)&&(x<=t))){ //cuando t=0 hay 1 conjunto
        return 1;
    }else{
        return 0;
    }
}