#include <stdio.h>
#include <math.h>
int main()
{
    float ia,ib,ja,jb,ka,kb,modA,modB,dotAB,crossABi,crossABj,crossABk,crossBAi,crossBAj,crossBAk,AngleAB,DegreeAB,UnitAi,UnitAj,UnitAk,UnitBi,UnitBj,UnitBk;
    int opt,opt2;
    //Gets the values of the vectors.
    definition:
    printf("Enter i of [A] Vector:");
    scanf("%f",&ia);
    printf("Enter j of [A] Vector:");
    scanf("%f",&ja);
    printf("Enter k of [A] Vector:");
    scanf("%f",&ka);
    printf("Enter i of [B] Vector:");
    scanf("%f",&ib);
    printf("Enter j of [B] Vector:");
    scanf("%f",&jb);
    printf("Enter k of [B] Vector:");
    scanf("%f",&kb);
    //Calculation Process.
    modA=sqrt(ia*ia+ja*ja+ka*ka);
    modB=sqrt(ib*ib+jb*jb+kb*kb);
    dotAB=(ia*ib+ja*jb+ka*kb);
    crossABi=(ja*kb-ka*jb);
    crossABj=-(ia*kb-ka*ib);
    crossABk=(ia*jb-ja*ib);
    crossBAi=-(ja*kb-ka*jb);
    crossBAj=(ia*kb-ka*ib);
    crossBAk=-(ia*jb-ja*ib);
    AngleAB=acos(dotAB/(modA*modB));
    DegreeAB=(AngleAB*180)/3.141593;
    UnitAi=ia/modA;
    UnitAj=ja/modA;
    UnitAk=ka/modA;
    UnitBi=ib/modB;
    UnitBj=jb/modB;
    UnitBk=kb/modB;
    //Query
    functions:
    printf("\n Select Option:");
    printf("\n\n1. Modulus of A Vector");
    printf("\n\n2. Modulus of B Vector");
    printf("\n\n3. Dot Product (AB)");
    printf("\n\n4. Cross Product (AxB)");
    printf("\n\n5. Cross Product (BxA)");
    printf("\n\n6. Angle Between A & B Vectors");
    printf("\n\n7. Unit Vector Towards A Vector");
    printf("\n\n8. Unit Vector Towards B Vector");
    printf("\n\n9. Print All of the Above");
    printf("\n\n Enter Selection: ");
    scanf("%d",&opt);
    //Output
    if(opt==1)
    {
        printf("\n\n mod(A) = %f",modA);
    }
    else if(opt==2)
    {
        printf("\n\n mod(B) = %f",modB);
    }
    else if(opt==3)
    {
        printf("\n\n dot(AB) = %f",dotAB);
    }
    else if(opt==4)
    {
        printf("\n\n cross(AB) = (%f)i + (%f)j + (%f)k",crossABi,crossABj,crossABk);
    }
    else if(opt==5)
    {
        printf("\n\n cross(BA) = (%f)i + (%f)j + (%f)k",crossBAi,crossBAj,crossBAk);
    }
    else if(opt==6)
    {
        printf("\n\n Angle(A,B) = %f Radian (%f Degree)",AngleAB,DegreeAB);
    }
    else if(opt==7)
    {
        printf("\n\n Unit(A) = (%f)i + (%f)j + (%f)k",UnitAi,UnitAj,UnitAk);
    }
    else if(opt==8)
    {
        printf("\n\n Unit(B) = (%f)i + (%f)j + (%f)k",UnitBi,UnitBj,UnitBk);
    }
    else if(opt==9)
    {
        printf("\n\n 1. mod(A) = %f",modA);
        printf("\n\n 2. mod(B) = %f",modB);
        printf("\n\n 3. dot(AB) = %f",dotAB);
        printf("\n\n 4. cross(AB) = (%f)i + (%f)j + (%f)k",crossABi,crossABj,crossABk);
        printf("\n\n 5. cross(BA) = (%f)i + (%f)j + (%f)k",crossBAi,crossBAj,crossBAk);        
        printf("\n\n 6. Angle(A,B) = %f Radian (%f Degree)",AngleAB,DegreeAB);
        printf("\n\n 7. Unit(A) = (%f)i + (%f)j + (%f)k",UnitAi,UnitAj,UnitAk);
        printf("\n\n 8. Unit(B) = (%f)i + (%f)j + (%f)k",UnitBi,UnitBj,UnitBk);
    }
    else
    {
        printf("\n\n Invalid Selection, Please Try Again.");
        goto functions;
    }
    //Termination and Looping.
    options:
    printf("\n\n Select Option:");
    printf("\n\n1. Reselect Function");
    printf("\n\n2. Redefine Vectors");
    printf("\n\n3. Terminate Program");
    printf("\n\n Enter Selection: ");
    scanf("%d",&opt2);
    if(opt2==1)
    {
        goto functions;
    }
    else if(opt2==2)
    {
        goto definition;
    }
    else if(opt2==3)
    {
        goto end;
    }
    else
    {
        printf("\n\nInvalid Selection, Please Try Again.");
        goto options;
    }
    end:
    return 0;
    


}