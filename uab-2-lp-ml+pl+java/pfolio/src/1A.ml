let listaA = [1,7,-8,5,4] 
let listaB = [9,6,3,-5,2] 
let listaC = [] 

let verifica valA valB = 
    if (valA > 0 && valB > 0) then (valA + valB)/2
    else valA + valB;; 

let obter listaA listaB listaC = 
    let ab = List.Map2 verifica listaA listaB 
    List.Map2 verifica ab listaC;; 

obter listaA listaB listaC;;