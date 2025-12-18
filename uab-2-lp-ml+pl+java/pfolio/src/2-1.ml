type 'a arvore = 
    Nil 
    | Node of 'a * 'a arvore * 'a arvore ;; 

let arvore = Node (3, Node (4, Node (6, Nil, Nil),Nil), 
                      Node (5, Node(9, Nil, Nil), Nil));;

let rec amplitudeFolhas aF = match aF with
    Node (x, Empty, Empty)
    | Node (x, left, right) -> amplitudeFolhas aF - amplitudeFolhas x;;
    
val recamplitudeFolhas : int bintree -> int = <fun>