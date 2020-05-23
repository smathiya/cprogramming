struct Wheel
{
   int dia;
   int width;
};

struct Car
{
    Wheel w[4];    
};

1) Car cars[5];  Tip: read it as Car[5] cars; cars is an array of Car

2) Car *cp = cars; cp is the address of the first element of cars array
cp->w[0]
(*cp).w[0]

second car's first wheel: (cp + 1)->w[0]
(*(cp + 1)).w[0]
cp[1].w[0]  Note: cp[1] is exactly same as (*(cp + 1))
 
3) Wheel *w31 = &(cars[3].w[1]);

4) Wheel *ww = (cars + 2)->w;
Note: Term Object is an instance of struct - Pointer is a variable that hold 
address of another variable (say int) or an object

5) Car *c2 = &cars[1]; Read it as &(cars[1])
what is c2[1]?  this is same as cars[2]

6) void *v1 = c2->w + 1; 
what is the value of v1? Address of second wheel of second car in "cars" array

7) Wheel wheels[3]; Tip: read it as Wheel[3] wheels;

Find the static type, dynamic type and sizeof of:
cars, cp, w31, ww, c2, v1, wheels

-----------------------------------------
1) Static type = Car  Answer: Car[]
   Dynamic type = Car Answer: Car[]
   Sizof(cars) = 160 correct // sizeof(cars[4]);  *(cars + 4)
   
   Car[] - [] serves as an array type operator
   mycars[x] - [] serves as an index operator
   
2) Static type = Car Answer: Car*
   Dynamic type = car Answer: Car[]
   Sizeof(cp) = 4 (32-bit)
 
3) Static type = wheel Answer: Wheel*
   Dynamic type = error Answer: array of Wheel
   Sizeof(w31) = 4
  
4) Static type = Wheel  Ans: Wheel*
   Dynamic type = error Ans: array of Wheel
   Sizeof (WW) = 4
   
 5) Static type = car Ans: Car* 
    Dyanamic type = car Ans: array of Car
    Sizeof ( c2)= 4
    
 6) Static type = void Ans: void*
    Dynamic type = car Ans: array of wheel (cant access)
    Sizeof(v1) = 4
 
 7) Static type = wheel Answer: Wheel[3]
    Dynamic type = wheel Answer: Wheel[3]
    Sizeof(wheels) = 96

/*
 
 Discussion: Sep 15
 
 Car cars[5] -> array of 5 cars
 static type of cars[0] is Car 
 cars itself is an array - Car[] or Car*
 for example, int x[5]; then x is of type int[]
 Any int array can be implicitly typecasted to int*
 Car *cp = cars; - cp has the address of first element of cars
 
 void PrintCars(Car *mycars, int count)
 {
     for (int i = 0; i < count; i++)
        printf(mycars[i].name);
 }
 
 Car other_cars[10];
 if (condition)
 {
     cp = cars;
 }
 else
    cp = other_cars;
 
 
 
  
 */
