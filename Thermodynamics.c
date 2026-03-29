#include <stdio.h>
#include <math.h>
#define  R  8.3144621
int box();
int pvnrt();
int pvk();
int pvgammak();
int wis();
int wad();
int wpdv();
int entropy();
int tempchange();
int efficiency();
int cop();
float pressure();
float volume();
float temperature();
float dq();

int main()
{
    int sel;
    start_here:
    box();
    printf("\n\nEnter Selection: ");scanf("%d",&sel);
    if(sel==1)
    {
        pvnrt();
    }
    else if(sel==2)
    {
        pvk();
    }
    else if(sel==3)
    {
        pvgammak();
    }
    else if(sel==4)
    {
        wis();
    }
    else if(sel==5)
    {
        wad();
    }
    else if(sel==6)
    {
        wpdv();
    }
    else if(sel==7)
    {
        entropy();
    }
    else if(sel==8)
    {
        tempchange();
    }
    else if(sel==9)
    {
        efficiency();
    }
    else if(sel==10)
    {
        cop();
    }
    else
    {
        printf("Invalid Selection. Please try again...");
        getch();
        goto start_here;
    }
    char again;
    printf("Press 'y' to Start Again. Press any Other Key to Terminate Program...");scanf("%c",&again);
    if(again=='y' || again=='Y')
    {
        goto start_here;
    }
    else
    {
        return 0;
    }

}

// Selection Box

int box()
{
    printf("\t Select from the functions below...");
    printf(
           "\n\n+--+---------------------------------------------+"
             "\n|01|        Calculate Unknown Using PV=nRT       |"
             "\n+--+---------------------------------------------+"
             "\n|02|        Calculate Unknown Using PV=k         |"
             "\n+--+---------------------------------------------+"
             "\n|03|    Calculate Unknown Using PV^(gamma)=k     |"
             "\n+--+---------------------------------------------+"
             "\n|04|  Calculate Work Done In Isothermal Process  |"
             "\n+--+---------------------------------------------+"
             "\n|05|   Calculate Work Done In Adiabatic Process  |"
             "\n+--+---------------------------------------------+"
             "\n|06|   Calculate Work Done in Isobaric Process   |"
             "\n+--+---------------------------------------------+"
             "\n|07|         Calculate Change of Entropy         |"
             "\n+--+---------------------------------------------+"
             "\n|08|  Calculate Temperature Using 2 Fixed Points |"
             "\n+--+---------------------------------------------+"
             "\n|09|    Calculate Efficiency of a Heat Engine    |"
             "\n+--+---------------------------------------------+"
             "\n|10|      Calculate C.O.P of a Refrigerator      |"
             "\n+--+---------------------------------------------+"
          );

    return 0;
}

// Calculate Unknown Using PV=nRT

int pvnrt()
{
   //Input Values
   
   float P,V,n,T;
   P=pressure();
   V=volume();
   T=temperature();
   printf("\n\nInput amount in mol.\nEnter amount: ");
   scanf("%f",&n);

   //Select Unknown Value.
   
   int un;
   measure_unknown:
   printf("\n\nSelect an unknown value to measure using the Ideal Gas Equation (PV=nRT)...");
   printf("\n\n+-------------+-----------+----------------+-----------+"
            "\n| 1. Pressure | 2. Volume | 3. Temperature | 4. Amount |"
            "\n+-------------+-----------+----------------+-----------+" );
   printf("\n\nSelect Option: ");
   scanf("%d",&un);
   if(un==1)
   {
      P=(n*R*T)/V;
      printf ("\n\nThe Calculated Pressure is %f Pa",P);
   }
   else if(un==2)
   {
      V=(n*R*T)/P;
      printf ("\n\nThe Calculated Volume is %f m^3",V);
   }
   else if(un==3)
   {
      T=(P*V)/(n*R);
      printf ("\n\nThe Calculated Temperature is %f K",T);
   }
   else if(un==4)
   {
      n=(P*V)/(R*T);
      printf ("\n\nThe Calculated Amount is %f mol",n);
   }
   else
   {
      printf("Invalid Input. Please Try Again...");
      goto measure_unknown;
   }

   getch();
   return 0;
}

// Calculate Unknown Using PV=k

int pvk()
{
   float P1,V1,T1,P2,V2,T2;
   printf("\nEnter Initial Values...");
   printf("\tNote: In case of ratios, input 1 Pa/m3/K as Initial and (ratio) Pa/m3/K as Final. Input a common value in both cases if it is constant.");
   P1=pressure();
   V1=volume();
   T1=temperature();
   printf("\n\n\t The Initial Values are:"
          "\n\t Pressure    P1 = %f Pa"
          "\n\t Volume      V1 = %f m3"
          "\n\t Temperature T1 = %f K ",P1,V1,T1);
   getch();
   unknown:
   printf("\n\n\tPlease Select Unknown Value:");
   printf  ("\n\t+-+----------------- +"
            "\n\t|1|Final Pressure    |"
            "\n\t|2|Final Volume      |"
            "\n\t|3|Final Temperature |"
            "\n\t+-+----------------- +");
   int un;
   printf("Unknown: ");
   scanf("%d",&un);
   if (un==1)
   {
      printf("\n\nEnter Final Values...");
      V2=volume();
      T2=temperature();
      P2=(P1*V1*T2)/(T1*V2);
      printf("\n\n\tThe Calculated Pressure is %f Pa",P2);
   }
   else if (un==2)
   {
      printf("\n\nEnter Final Values...");
      P2=pressure();
      T2=temperature();
      V2=(P1*V1*T2)/(T1*P2);
      printf("\n\n\tThe Calculated Volume is %f m3",V2);
   }
   else if (un==3)
   {
      printf("\n\nEnter Final Values...");
      P2=pressure();
      V2=volume();
      T2=(P2*V2*T1)/(P1*V1);
      printf("\n\n\tThe Calculated Temperature is %f K",T2);
   }
   else
   {
      printf("Invalid Input. Please Try Again...");
      getch();
      goto unknown;
   }
   getch();
   return 0;

}

// Calculate Unknown Using PV^(gamma)=k

int pvgammak()
{
   float P1,V1,T1,P2,V2,T2,g;
   printf("\nEnter Value of Gamma. (Usually 1.4 for atmospheric gases.)"
          "\nGamma = ");
   scanf("%f",&g);
   float g1=1-g; //since it's used a lot, decided to assign a var. to 1-g
   selection:
   printf("\n\n\tPlease Select Unknown Value: \tNote that it won't be present in the equation.");
   printf  ("\n\t+-+------------+"
            "\n\t|1|Pressure    |"
            "\n\t|2|Volume      |"
            "\n\t|3|Temperature |"
            "\n\t+-+------------+");
   int un;
   printf("\n\n\tUnknown: ");
   scanf("%d",&un);
   printf("\n\n\tPlease Select Target Value:");
   printf  ("\n\t+-+------------+"
            "\n\t|1|Pressure    |"
            "\n\t|2|Volume      |"
            "\n\t|3|Temperature |"
            "\n\t+-+------------+");
   int ta;
   printf("\n\n\tTarget: ");
   scanf("%d",&ta);
   if(un==ta)
   {
      printf("\n\n\tERROR : Your Target Value Must be Present in the Equation....");
      goto selection;
   }
   else if(un==1)
   {
      printf("\nEnter Initial Values...");
      printf("\tNote: In case of ratios, input 1 Pa/m3/K as Initial and (ratio) Pa/m3/K as Final.");
      V1=volume();
      T1=temperature();
      if(ta==2)
      {
        printf("\nEnter Final Temperature...");
        T2=temperature();
        V2=(T1/T2)*pow(V1,g1);
        printf("\n\n\tThe Calculated Volume is %f m3",V2);
      }
      else if(ta==3)
      {
        printf("\nEnter Final Volume...");
        V2=volume();
        T2=T1*pow((V1/V2),g1);
        printf("\n\n\tThe Calculated Pressure is %f K",T2);
      }
      else
      {
        printf("Invalid Selection. Try Again...");
        getch();
        goto selection;
      }
   }
   else if(un==2)
   {
      printf("\nEnter Initial Values...");
      printf("\tNote: In case of ratios, input 1 Pa/m3/K as Initial and (ratio) Pa/m3/K as Final.");
      P1=pressure();
      T1=temperature();
      if(ta==1)
      {
        printf("\nEnter Final Temperature...");
        T2=temperature();
        P2=pow((T1/T2),g)*pow(P1,g1);
        printf("\n\n\tThe Calculated Pressure is %f Pa",P2);
      }
      else if(ta==3)
      {
        printf("\nEnter Final Pressure...");
        P2=pressure();
        T2=pow(T1,g)*pow((P1/P2),g1);
        printf("\n\n\tThe Calculated Temperature is %f K",T2);
      }
      else
      {
        printf("Invalid Selection. Try Again...");
        getch();
        goto selection;
      }
   }
   else if(un==3)
   {
      printf("\nEnter Initial Values...");
      printf("\tNote: In case of ratios, input 1 Pa/m3/K as Initial and (ratio) Pa/m3/K as Final.");
      P1=pressure();
      V1=volume();
      if(ta==1)
      {
        printf("\nEnter Final Volume...");
        V2=volume();
        P2=P1*pow((V1/V2),g);
        printf("\n\n\tThe Calculated Pressure is %f Pa",P2);
      }
      else if(ta==2)
      {
        printf("\nEnter Final Pressure...");
        P2=pressure();
        V2=pow(V1,g)*(P1/P2);
        printf("\n\n\tThe Calculated Volume is %f m3",V2);
      }
      else
      {
        printf("Invalid Selection. Try Again...");
        getch();
        goto selection;
      }
   }
   else
   {
      printf("Invalid Selection. Try Again...");
      getch();
      goto selection;
   }
   getch();
   return 0;

}

// Calculate Work Done In Isothermal Process

int wis()
{
   float n,T,V1,V2,W;
   printf("\n\nEnter amount of gas in mol :");
   scanf("%f",&n);
   T=temperature();
   printf("\n\nEnter Initial Volume...");
   V1=volume();
   printf("\n\nEnter Final Volume...");
   V2=volume();
   printf("\n\n\tThe Entered Values are :"
              "\nAmount,         n  = %f mol"
              "\nTemperature,    T  = %f K  "
              "\nInitial Volume, V1 = %f m3 "
              "\nFinal Volume,   V2 = %f m3 ",n,T,V1,V2);
   getch();
   W=n*R*T*log(V2/V1);
   printf("\n\n\tThe Calculated Work Done is %f Joule",W);
   getch();
   return 0;
}

// Calculate Work Done In Adiabatic Process

int wad()
{
   float P1,V1,T1,P2,V2,T2,g,W;
   printf("\nEnter Value of Gamma. (Usually 1.4 for atmospheric gases.)"
          "\nGamma = ");
   scanf("%f",&g);
   selection:
   printf("\n\nSelect Method of Calculation:"
            "\n1. Calculate Using Pressure & Volume."
            "\n2. Calculate Using Temperature & Amount."
          "\n\nSelection: ");
   int sel;
   scanf("%d",&sel);
   if(sel==1)
   {
        printf("\n\nEnter Initial Values...");
        P1=pressure();
        V1=volume();
        printf("\nEnter Final Values...");
        P2=pressure();
        V2=volume();
        printf("\n\n\tThe Entered Values are :"
              "\nGamma,            g  = %f    "
              "\nInitial Pressure, P1 = %f Pa "
              "\nInitial Volume,   V1 = %f m3 "
              "\nFinal Pressure,   P2 = %f Pa "
              "\nFinal Volume,     V2 = %f m3 ",g,P1,V1,P2,V2);
        getch();
        W=(1/(g-1))*((P1*V1)-(P2*V2));
        printf("\n\n\tThe Calculated Work Done is %f Joule",W);
        getch();
        return 0;
   }
   else if(sel==2)
   {
        float n;
        printf("\n\nEnter amount of gas in mol :");
        scanf("%f",&n);
        printf("\n\nEnter Initial Values...");
        T1=temperature();
        printf("\nEnter Final Values...");
        T2=temperature();
        printf("\n\n\tThe Entered Values are :"
              "\nGamma,               g  = %f    "
              "\nAmount,              n  = %f mol"
              "\nInitial Temperature, T1 = %f K  "
              "\nFinal Temperature,   T2 = %f K  ",g,n,T1,T2);
        getch();
        W=((n*R)/(g-1))*(T1-T2);
        printf("\n\n\tThe Calculated Work Done is %f Joule",W);
        getch();
        return 0;
   }
   else
   {
        printf("Invalid Selection. Please Try Again...");
        goto selection;
   }
}

// Calculate Work Done in Isobaric Process

int wpdv()
{
    float P,V1,V2,W;
    P=pressure();
    printf("Enter Initial Value...");
    V1=volume();
    printf("Enter Final Value...");
    V2=volume();
    printf("\n\n\tThe Entered Values are :   "
               "\nPressure,       P  = %f Pa "
               "\nInitial Volume, V1 = %f m3 "
               "\nFinal Volume,   V2 = %f m3 ",P,V1,V2);
    getch();
    W=P*(V2-V1);
    printf("\n\n\tThe Calculated Work Done is %f Joule",W);
    getch();
    return 0;

}

// Calculate Change of Entropy

int entropy()
{
    int sel;
    float dQ,T,T1,T2,m,s,dS;
    selection:
    printf("\n\nCalculate Entropy in the case of..."
             "\n1. State Change."
             "\n2. Temperature Change."
           "\n\nSelection: ");scanf("%d",&sel);
    if(sel==1)
    {
        dQ=dq();
        T=temperature();
        dS=dQ/T;
        printf("\n\n\tThe calculated change in entropy is %f Joule/Kelvin",dS);
    }
    else if(sel==2)
    {
        printf("\nEnter Mass of Object: ");          scanf("%f",&m);
        printf("\nEnter Specific Heat of Object: "); scanf("%f",&s);
        printf("\nEnter Initial Temperature...");    T1=temperature();
        printf("\nEnter Final Temperature...");      T2=temperature();
        dS=m*s*log(T2/T1);
        printf("\n\n\tThe calculated change in entropy is %f Joule/Kelvin",dS);
    }
    else
    {
        printf("\n\n\tInvalid Input. Please try again...");
        getch();
        goto selection;
    }
    getch();
    return 0;
}

// Calculate Temperature Using 2 Fixed Points

int tempchange()
{
    float x,xs,xi,tc,tf,tk;
    printf("\n\nEnter fixed points of 'X' Measuring Thermometer");
    printf("\nIce Point   : ");scanf("%f",&xi);
    printf("\nSteam Point : ");scanf("%f",&xs);
    selection:
    printf("\n\nSelect function:"
             "\n1. Calculate 'X' using Traditional Temperature Values (C,F,K to X)"
             "\n2. Calculate Traditional Temperature Values using 'X' (X to C,F,K)"
           "\n\nSelection:");int sel;scanf("%d",&sel);
    if(sel==1)
    {
          tk=temperature();
          x=(((tk-273)*(xs-xi))/100)+xi;
          tc=tk-273;
          tf=((9*tc)/5)+32;
          printf("\n\n\t+---+---------------------"
                   "\n\t| C | %f degree"
                   "\n\t+---+---------------------"
                   "\n\t| F | %f degree"
                   "\n\t+---+---------------------"
                   "\n\t| K | %f Kelvin"
                   "\n\t+---+---------------------"
                   "\n\t| X | %f unit"
                   "\n\t+---+---------------------\n",tc,tf,tk,x);
          getch();
          return 0;
    }
    else if(sel==2)
    {
          printf("Enter 'X' Temperature: ");scanf("%f",&x);
          tk=(((x-273)*(xs-xi))/100)+xi;
          tc=tk-273;
          tf=((9*tc)/5)+32;
          printf("\n\n\t+---+---------------------"
                   "\n\t| X | %f "
                   "\n\t+---+---------------------"
                   "\n\t| C | %f "
                   "\n\t+---+---------------------"
                   "\n\t| F | %f "
                   "\n\t+---+---------------------"
                   "\n\t| K | %f "
                   "\n\t+---+---------------------",x,tc,tf,tk);
          getch();
          return 0;
    }
    else
    {
          printf("\n\n\tInvalid Selection. Please Try Again...");
          getch();
          goto selection; 
    }
}

// Calculate Efficiency of a Heat Engine

int efficiency()
{
    float eff;
    char carnot;
    iscarnot:
    printf("\n\nIs it a Carnot Engine? (y/n) :");
    scanf("%c",&carnot);
    if(carnot=='y' || carnot=='Y')
    {
        char meas;
        select_th:
        printf("\nMeasure using Temperature or Heat? (t/h) :");
        scanf("%c",&meas);
        if(meas=='t' || meas=='T')
        {
            float t1,t2;
            printf("\n\nEnter Temperature of Heat Source...");
            t1=temperature();
            printf("\nEnter Temperature of Heat Sink...");
            t2=temperature();
            eff=(1-(t2/t1));
        }
        else if(meas=='h' || meas=='H')
        {
            float q1,q2;
            printf("\n\nHeat Intake (Joule): ");scanf("%f",&q1);
            printf(  "\nHeat Output (Joule): ");scanf("%f",&q2);
            eff=(1-(q2/q1));
        }
        else
        {
            printf("\n\nInvalid Input. Please Try Again...");
            getch();
            goto select_th;
        }
    }
    else if(carnot=='n' || carnot=='N')
    {
        printf("\n\nMeasuring Efficiency Using Heat Values...");
        float q1,q2;
        printf("\n\nHeat Intake (Joule): ");scanf("%f",&q1);
        printf(  "\nHeat Output (Joule): ");scanf("%f",&q2);
        eff=(1-(q2/q1));
    }
    else
    {
        printf("Invalid Input. Please Try Again...");
        getch();
        goto iscarnot;
    }
    printf("\n\n\tThe Calculated Efficiency is %f which is %f%%",eff,eff*100);
    getch();
    return 0;
}

// Calculate C.O.P of a Refrigerator

int cop()
{
    float qh,ql,th,tl,w,cop;
    char hete;
    select:
    printf("\n\nCalculate Using: Heat, Temperature or Work Done by Compressor? (h/t/w) : ");scanf("%c",&hete);
    if(hete=='h' || hete=='H')
    {
        printf("\nCalculating using heat...");
        printf("\n\nEnter Absorbed Heat (Joule) : ");scanf("%f",&ql);
        printf(  "\nEnter Released Heat (Joule) : ");scanf("%f",&qh);
        cop=ql/(qh-ql);
    }
    else if(hete=='t' || hete=='T')
    {
        printf("\nCalculating using temperature...");
        printf("\nEnter temperature of Heat Sink...");
        tl=temperature();
        printf("\nEnter temperature of Heat Source...");
        th=temperature();
        cop=tl/(th-tl);
    }
    else if(hete=='w' || hete=='W')
    {
        printf("\nCalculating using work done by compressor...");
        printf("\n\nEnter Absorbed Heat (Joule)           : ");scanf("%f",&ql);
        printf(  "\nEnter Work Done by Compressor (Joule) : ");scanf("%f",&w);
        cop=ql/w;
    }
    else
    {
        printf("Invalid Input. Please try again...");
        getch();
        goto select;
    }
    printf("\n\n\tThe Calculated Coefficient of Performance (COP) is %f",cop);
    getch();
    return 0;
}

// Pressure Calculation...

float pressure()
{   
   float P,P1;
   char unitP [4];
   pressure_input:
   printf("\n\nEnter Pressure = ");
   scanf("%f",&P);
   scanf("%s",&unitP);
   printf("\n\nProvided pressure is %f %s",P,unitP);
   if(unitP[0]=='a' && unitP[1]=='t' && unitP[2]=='m')
   {
      P1=P*101325; //Since 1 atm = 101325 Pa
   }
   else if((unitP[0]=='m' && unitP[1]=='m' && unitP[2]=='H' && unitP[3]=='g') || (unitP[0]=='t' && unitP[1]=='o' && unitP[2]=='r' && unitP[3]=='r') )
   {
      P1=(P/760)*101325; //Since 1 atm = 760 mmHg = 760 torr = 101325 Pa
   }
   else if(unitP[0]=='P' && unitP[1]=='a')
   {
      P1=P;
   }
   else if((unitP[0]=='k' && unitP[1]=='P' && unitP[2]=='a') || (unitP[0]=='b' && unitP[1]=='a' && unitP[2]=='r'))
   {
      P1=P*1000; //Since 1 kPa = 1 Bar = 1000 Pa
   }
   else
   {
      printf("\n\nInvalid Unit... Please Try Again.");
      goto pressure_input;
   }
   printf("\n\nWhich is equal to %f Pa",P1);
   return P1;
}

// Volume Calculation...

float volume()
{
   float V,V1;
   char unitV [4];
   volume_input:
   printf("\n\nEnter Volume = ");
   scanf("%f",&V);
   scanf("%s",&unitV);
   printf("\n\nProvided volume is %f %s",V,unitV);
   if(unitV[0]=='m' && unitV[1]=='3')
   {
      V1=V;
   }
   else if((unitV[0]=='L') || (unitV[0]=='d' && unitV[1]=='m' && unitV[2]=='3'))
   {
      V1=V*0.001; //Since 1 m3 = 1000 L
   }
   else if((unitV[0]=='c' && unitV[1]=='c') || (unitV[0]=='m' && unitV[1]=='L'))
   {
      V1=V*(pow(10, -6)); //Since 1 m3 = 1000 L = 1000*1000 mL = 10^6 cc
   }
   else
   {
      printf("\n\nInvalid Unit... Please Try Again.");
      goto volume_input;
   }
   printf("\n\nWhich is equal to %f Cubic Meter",V1);
   return V1;

}

// Temperature Calculation...

float temperature()
{
   float T,T1;
   char unitT[1];
   temp_input:
   printf("\n\nEnter Temperature = ");
   scanf("%f",&T);
   scanf("%s",&unitT);
   printf("\n\nProvided temperature is %f %s",T,unitT);
   if(unitT[0]=='K')
   {
      T1=T;
   }
   else if(unitT[0]=='F')
   {
      T1=(((T-32)/9)*5)+273; //Since C=((F-32)/9)*5 and K=C+273
   }
   else if(unitT[0]=='C')
   {
      T1=T+273;
   }
   else
   {
      printf("\n\nInvalid Unit... Please Try Again.");
      goto temp_input;
   }
   printf("\n\nWhich is equal to %f Kelvin",T1);
   return T1;

}

// Change of Heat Energy Calculation

float dq()
{
    float mass,lat,dq;
    printf("\n\nEnter mass of the object... (in kg)");
    printf("\nMass = ");
    scanf("%f",&mass);
    printf("\nEnter latent heat of said object and event (vaporisation or liquefaction)... (in J/kg).");
    printf("\nLatent Heat = ");
    scanf("%f",&lat);
    dq=mass*lat;
    printf("\nThe change in Heat Energy is %f Joule",dq);
    getch();
    return dq;
}

// EL PSY CONGROO //
