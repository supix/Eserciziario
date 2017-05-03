bool Lista::_CodaPari(const PRec p) const {
  if (p) {
    if (p->succ)
      return _CodaPari(p->succ);
    else
      return ((p->el % 2) == 0);
  } else
    return 0;   
}  

bool Lista::CodaPari() const {
  return _CodaPari(first);
}
