#pragma once
#include <concepts>
#include <numeric>

template<typename I> requires std::integral<I>
class rational
{ 
    I num_;
    I den_;

public:
    // Costruttore di default //
    rational()
        : num_(0), den_(1) {}   

    // Costruttore user-defined // 
    rational(const I& px, const I& py) 
        : num_(px), den_(py) 
    {
        if (den_ == 0) {
            if (num_ == 0) {
                // NaN
                num_ = 0;
                den_ = 0;
            } 
            else if (num_ > 0) {
                // +Inf
                num_ = 1;
                den_ = 0;
            } 
            else {
                // -Inf
                num_ = -1;
                den_ = 0;
            }
        }
    }

    I num() const { return num_; } 
    I den() const { return den_; }

    // Stati //
    bool isNaN() const { return num_ == 0 && den_ == 0; }
    bool isInf() const { return den_ == 0 && num_ != 0; }
    bool isNormal() const { return den_ != 0; }
	
	
	void simplify() {
        // Non semplificare se NaN o Inf
        if (isNaN() || isInf()) return;

        I g = std::gcd(num_, den_);  // massimo comune divisore
        num_ /= g;
        den_ /= g;

        // Normalizza segno: il denominatore deve essere positivo
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
		}
}


// Operatore += che modifica l’oggetto corrente //
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
	
/*Implementazionecanonica dellasomma*/
rational operator+( const rational& other) const{
   rational ret = *this;
   ret += other;
   return ret;
   }
   
 
 rational& operator-=(const rational& other) {
    // Se almeno uno è NaN → risultato = NaN
    if (isNaN() || other.isNaN()) {
        num_ = 0;
        den_ = 0;
        return *this;
    }

    // Inf - Inf
    if (isInf() && other.isInf()) {
        if (num_ == other.num_) {
            // +Inf - +Inf oppure -Inf - -Inf = NaN
            num_ = 0;
            den_ = 0;
            return *this;
        } else {
            // +Inf - -Inf = +Inf
            // -Inf - +Inf = -Inf
            return *this;
        }
    }

    // Inf - normale
    if (isInf()) return *this;

    // normale - Inf
    if (other.isInf()) {
        num_ = -other.num_; // cambia segno
        den_ = 0;
        return *this;
    }

    // Sottrazione normale di razionali
    num_ = num_ * other.den() - other.num() * den_;
    den_ = den_ * other.den();

    // Normalizzazione segno
    if (den_ < 0) {
        num_ = -num_;
        den_ = -den_;
    }

    return *this;
}



/*Implementazionecanonica della sottrazione*/
rational operator-( const rational& other) const{
   rational ret = *this;
   ret -= other;
   return ret;
   }
   
   
 rational& operator*=(const rational& other) {
    // Se almeno uno è NaN → risultato = NaN
    if (isNaN() || other.isNaN()) {
        num_ = 0;
        den_ = 0;
        return *this;
    }

    // 0 * Inf → NaN
    if ((isInf() && other.num_ == 0 && other.den_ != 0) ||
        (other.isInf() && num_ == 0 && den_ != 0)) {
        num_ = 0;
        den_ = 0;
        return *this;
    }

    // Inf * Inf
    if (isInf() && other.isInf()) {
        if (num_*other.num_ > 0) {
        num_ = 1;
        } else {
        num_ = -1;
        }
        den_ = 0;
        return *this;
    }

    // Inf * normale
    if (isInf()) {
        if (num_ > 0) {
        num_ = 1;
        } else {
        num_ = -1;
          }
        den_ = 0;
        return *this;
    }

    // normale * Inf
    if (other.isInf()) {
        if (num_ > 0) {
        num_ = 1;
        } else {
          num_ = -1;
          }
        den_ = 0;
        return *this;
    }

    // Moltiplicazione normale
    num_ *= other.num();
    den_ *= other.den();

    // Normalizzazione segno
    if (den_ < 0) {
        num_ = -num_;
        den_ = -den_;
    }

    return *this;
}



/*Implementazionecanonica del prodotto*/
rational operator*( const rational& other) const{
   rational ret = *this;
   ret *= other;
   return ret;
   }
   
   
   
rational& operator/=(const rational& other) {
    // NaN coinvolto → NaN
    if (isNaN() || other.isNaN()) {
        num_ = 0;
        den_ = 0;
        return *this;
    }

    // divisione per 0 → Inf o NaN
    if (other.num_ == 0 && other.den_ != 0) {
        if (num_ == 0) {
            // 0 / 0 → NaN
            num_ = 0;
            den_ = 0;
        } else {
            // x / 0 → ±Inf
            if (num_ > 0) {
            num_ = 1;
            } else {
            num_ = -1;
              }
            den_ = 0;
        }
        return *this;
    }

    // Inf / Inf → NaN
    if (isInf() && other.isInf()) {
        num_ = 0;
        den_ = 0;
        return *this;
    }

    // Inf / normale → Inf
    if (isInf()) {
        if (num_ > 0) {
        num_ = 1;
    } else {
    num_ = -1;
      }
      den_ = 0;
        return *this;
    }

    // normale / Inf → 0
    if (other.isInf()) {
        num_ = 0;
        den_ = 1;
        return *this;
    }

    // Caso normale: moltiplica per il reciproco
    num_ *= other.den();
    den_ *= other.num();

    // Se il denominatore diventa 0 → gestisci Inf
    if (den_ == 0) {
        if (num_ > 0) {
        num_ = 1;
        } else {
          num_ = -1;
           }
        return *this;
    }

    // Normalizzazione segno
    if (den_ < 0) {
        num_ = -num_;
        den_ = -den_;
    }

    return *this;
}



/*Implementazionecanonica della divisione*/
rational operator/( const rational& other) const{
   rational ret = *this;
   ret /= other;
   return ret;
   }
};