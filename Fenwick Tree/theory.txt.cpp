fen[i] represents range sum of [f(i) + 1, i]
f(i) = number you get by turning of lsb
       fen[5] => f(5) = f(101) = 100 == > fen[5] = [5, 5]

                                 to check how many indices you have to update == >
                                 take 2's complement
                                 & it with orig number
                                 add res to orig num
                                 ind = ind+(ind& ~ind);
                                 query
                                 -> find 2's complement
                                 -> and with orig num
                                 -> subtract res from orig num
                                 -- > do this till ind > 0