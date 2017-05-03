class AlberoBinario {
private:

  ...

  const int maxocc;

  ...

  bool _Inserisci(PNodo& n, const TElem& el, int curr_occ);
public:
  AlberoBinario(unsigned int max_occ);

  ...

  bool Inserisci(const TElem& el);
};
