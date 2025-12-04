program part2
  implicit none
  
  character(len=100) :: line
  integer(8) :: ans = 0
  integer(8) :: i, j, digit, maxdigit, maxpos

  do
    read(*, '(a100)', end=9999) line
    maxdigit = -1
    maxpos = 0
    do i = 12, 1, -1
      do j = maxpos + 1, 100 - i + 1
        read(line(j:j), '(i1)') digit
        if (digit > maxdigit) then
          maxdigit = digit
          maxpos = j
        end if
      end do
      ans = ans + (maxdigit * (10 ** (i - 1)))
      maxdigit = -1
    end do
  end do

9999 continue
  print *, ans
end program part2
