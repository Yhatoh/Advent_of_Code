program part1
  implicit none

  character(len=1) :: dir
  integer :: move

  integer :: curr = 50
  integer :: ans = 0

  do
    read(*, '(a1, i6)', end=9000) dir, move
    if (dir == 'L') then
      curr = curr - move
      curr = curr + 100
      curr = mod(curr, 100)
    else
      curr = curr + move
      curr = mod(curr, 100)
    end if
    !print '(a1, 1X, i2, 1X, i2)', dir, move, curr
    if (curr == 0) then
      ans = ans + 1
    end if
  end do

9000 continue
  print '(i6)', ans

end program part1
