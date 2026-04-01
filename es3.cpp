template<typename I> requires std::integral<I>
class rational
{ 
   I num_;
   I den_;
};
public:
  /*Costruttore di default*/
  rational()
     :num_(I{0.0}),den_(I{0.0})
  {} 
  /*Costruttore user-defined */ 
  rational(const I& px,const I& py) 
     :num_(px), den_(py) 
  {
	  if (den_ == 0){
		  if (num_ == 0){
			  // NaN
                num_ = 0;
                den_ = 0;
                std::cout << "Attenzione: questo è NaN\n";
            } else {
				if (num_>0){
                //+ Inf
				num_ = 1
                den_ = 0;
                std::cout << "Attenzione: questo è Inf\n";
				else{
					//- Inf
				    num_ = -1
                    den_ = 0;
                }
			}
		}
			  
  } 
  /*Restituiscono i valori di x e y*/ 
  I num() const {return num_;} 
  I den() const {return den_;}
  
  
  bool isNaN() const { return num_ == 0 && den_ == 0; }
  bool isInf() const { return den_ == 0 && num_ != 0; }
  bool isNormal() const { return den_ != 0; }
  
  

   
    /* Operatore += che modifica l’oggetto corrente */
    rational& operator+=(const rational& other) {
        // Se  almeno uno è NaN risultato = NaN
        if (isNaN() || other.isNaN()) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        // Inf + Inf
        if (isInf() && other.isInf()) {
            if (num_ ==other.num_) {
                // +Inf + +Inf = +Inf
                return *this;
            } else {
                // +Inf + -Inf = NaN
                num_ = 0;
                den_ = 0;
                return *this;
            }
        }

        // Inf + normale
        if (isInf()) return *this;
        if (other.isInf()) {
            num_ = other.num_;
            den_ = 0;
            return *this;
        }

        // Somma normale di razionali
        num_ = num_ * other.den() + other.num() * den_;
        den_ = den_ * other.den();
		
		// Normalizzazione segno
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }

        return *this;
    }
	
	/* Operatore + che ritorna un nuovo rational */
    rational operator+(const rational& other) const {
        // Se uno è NaN → risultato = NaN
        if (isNaN() || other.isNaN()) {
            return rational(0,0);
        }

        // Inf + Inf
        if (isInf() && other.isInf()) {
            if (num_ ==other.num_ ) {
                // +Inf + +Inf = +Inf
                return *this;
            } else {
                // +Inf + -Inf = NaN
                return rational(0,0);
            }
        }

        // Inf + normale
        if (isInf()) return *this;
        if (other.isInf()) return other;

        // Somma normale di razionali
        I new_num = num_ * other.den() + other.num() * den_;
        I new_den = den_ * other.den();

        // Normalizzazione segno
        if (new_den < 0) {
            new_num = -new_num;
            new_den = -new_den;
        }
		
	/* Operatore -= che modifica l’oggetto corrente */
    rational& operator-=(const rational& other) {
        // Se  almeno uno è NaN risultato = NaN
        if (isNaN() || other.isNaN()) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        // Inf - Inf
        if (isInf() && other.isInf()) {
            if (num_ ==other.num_) {
                // +Inf + +Inf = +Inf
                return *this;
            } else {
                // +Inf + -Inf = NaN
                num_ = 0;
                den_ = 0;
                return *this;
            }
        }

        // Inf + normale
        if (isInf()) return *this;
        if (other.isInf()) {
            num_ = other.num_;
            den_ = 0;
            return *this;
        }

        // Somma normale di razionali
        num_ = num_ * other.den() + other.num() * den_;
        den_ = den_ * other.den();
		
		// Normalizzazione segno
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }

        return *this;
    }
