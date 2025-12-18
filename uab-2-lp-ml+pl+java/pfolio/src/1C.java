ArrayList<Integer> ListaA = new ArrayList<Integer>(Arrays.asList(1,7,-8,5,4)); 
ArrayList<Integer> ListaB = new ArrayList<Integer>(Arrays.asList(9,6,3,-5,2)); 
ArrayList<Integer> ListaC = new ArrayList<Integer>(); 

for (int i = 0; i < ListaA.size(); i++) 
{ 
    int valA = ListaA.get(i); 
    int valB = ListaB.get(i); 

    if (valA > 0 && valB > 0) 
        ListaC.add((valA + valB)/2);  
    else 
        ListaC.add(valA + valB); 
} 

for (int i = 0; i < ListaC.size(); i++)
{ 
    if (i > 0) 
        System.out.print(", ");

    System.out.print(ListaC.get(i)); 
}