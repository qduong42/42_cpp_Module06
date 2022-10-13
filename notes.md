# Ex00
## Parsing:
- strtod => return value + **endptr
- Allowed: single char or number + f
- check cahr for ascii value
1. Convert to double intermediary
2. convert to needed types

# Ex01
- reinterpret_cast to cast from data* to uintptr_t 
- used to serialize/deserialize Object instances

# Ex02
- dynamic_cast


# All types of casts notes:

1. static_cast should be first cast attempted.
    - reverse implicit conversion
    - no runtime check
    - Through inheritance hierarchies.
        - upward cast (towards base class) obsolete
        - downward cast only works without virtual inheritance. => down to derived classes.
        - BUT it doesnt check type of object.
2. const_cast add or remove const to var.
3. dynamic_cast => exclusively handling polymorphism - Run-time type information => up/down class hierarchies
    - casting downwards/sideways/up another chain.
    - seeks out desired object and return if possible
    - otherwise return nullptr or throw std::bad_cast in case of ref.
    - LIMITATIONS: CANT multiple obj same type in inheritance hierarchy (dreaded diamond) without virtual. ONLY WORK with public inheritance.
4. reinterpret_cast
    - most dangerous => turns one type directly to another. => storing pointer in ant
    - Guarantee: if you cast result back, you get same value, but only if size is same as original type.
    - Bit casting.
5. C-style:
   - const cast
   - static cast
   - access control..?
