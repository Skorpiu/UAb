let pH = 120 in
let sH = 140 in
let tH = 150 in
let resto = 155 in

let parque horaE horaS minE minS = 
  (horaS*60 + minS) - (horaE*60 + minE)

  if parque <= 0 then parque += 1440
    else parque%60 != 0 then parque += (60 - parque%60)

  if parque > 0 and <= 60 then pH
    else if parque > 60 and <= 120 then pH + sH
      else if parque > 120 and <= 180 then pH + sH + tH
        else if parque > 180 then pH + sH + tH + resto*module(4 - parque/60) ;;