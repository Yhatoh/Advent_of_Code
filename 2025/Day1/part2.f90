program part2
  implicit none

  character(len=1) :: dir
  integer :: move

  integer :: curr = 50
  integer :: ans = 0
  integer :: rot = 0
  do
    read(*, '(a1, i6)', end=9000) dir, move

    if (dir == 'L') then
      ans = ans + (move / 100)
      move = mod(move, 100)
      if (curr - move < 0 .and. curr /= 0) then
        ans = ans + 1
      endif
      curr = curr - move
      curr = curr + 100
      curr = mod(curr, 100)
    else
      ans = ans + (move / 100)
      move = mod(move, 100)
      if (curr + move > 100 .and. curr /= 0) then
        ans = ans + 1
      endif
      curr = curr + move
      curr = mod(curr, 100)
    end if
    if (curr == 0) then
      ans = ans + 1
    end if
    !print *, dir, move, ans, curr
    rot = 0
  end do

9000 continue
  print '(i6)', ans

end program part2
