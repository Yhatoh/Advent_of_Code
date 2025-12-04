program part1
  implicit none
  
  character(len=100) :: line
  integer :: ans = 0
  integer :: i, digit, maxdigit, maxpos
  integer :: secdigit

  do
    read(*, '(a100)', end=9999) line
    maxdigit = -1
    maxpos = -1
    do i = 1, 99
      read(line(i:i), '(i1)') digit
      if (digit > maxdigit) then
        maxdigit = digit
        maxpos = i
      end if
    end do

    secdigit = -1
    do i = maxpos + 1, 100
      read(line(i:i), '(i1)') digit
      if (digit > secdigit) then
        secdigit = digit
      end if
    end do
    ans = ans + (maxdigit * 10 + secdigit)
  end do

9999 continue
  print *, ans
end program part1
