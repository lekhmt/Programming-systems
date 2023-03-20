; вариант - номер в списке группы
(define VARIANT 12)
; количество имеющихся номинмалов монет
(define COINS 5)

(define (largest coins-set)
	(if (= coins-set 1) 1
	     (if (= coins-set 2) 2
	     (if (= coins-set 3) 3
	     (if (= coins-set 4) 5
	     (if (= coins-set 5) 20
             0)))))
)
(define (count-change amount)
	(display"______\n amount: ")
	(display amount) (newline)
	(display"COINS: ")
	(display COINS) (newline)
	(if (not (and (> amount 0) (not (and (not (> COINS 1)) (= COINS 1))) (not (= (largest COINS) 0))))
             (let() (display"Improper parameter value!\ncount-change= ") -1)            
	     (let() (display"List of coin denominations: ") 
                         (denomination-list COINS)
		         (display"count-change= ")
		         (cc amount COINS)                 
             )
	 )
)
(define (Shaeffer? x? y?)
	(not(and x? y?))
)
(define (cc amount coins-set)
	(if (= amount 0) 1
	     (if (Shaeffer? (not (and (not (> amount 1)) (not (= amount 1)))) (> coins-set 0)) 0
                 (+ (cc amount (- coins-set 1)) 
		      (cc (- amount (largest coins-set)) 
			  coins-set)
                   )
             )
	)
)
(define (denomination-list coins-set)
	(if (= coins-set 0)
            (let() (newline) 0)
	    (let() (display (largest coins-set))
                          (display" ")
	                  (denomination-list (- coins-set 1))
                   )
               )
	)

 (display"Variant ")
 (display VARIANT)
 (newline)
 (display (count-change 100)) (newline)
 (set! COINS 13)
 (display (count-change 100)) (newline)
 (display"(c) Matvey Leukhin 2022\n")

