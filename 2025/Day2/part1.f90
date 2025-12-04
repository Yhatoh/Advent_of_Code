program part1
  implicit none

  integer(8) :: l, r, i, j, p, q
  integer(8) :: pos
  integer(8) :: ans = 0
  integer(8) :: flag = 0
  integer(8) :: length, aux

  character(len=500) line
  character(len=20) s_l, s_r, s_num
  read(*, '(a)') line

  do
    pos = index(line, ',')
    if (pos == 0) then
      exit
    end if
    s_l = line(1:index(line, '-') - 1)
    s_r = line(index(line, '-') + 1:pos - 1)
    read(s_l, *) l
    read(s_r, *) r
    print *, l, r
    line = line(pos + 1:len(line))
    ids: do i = l, r
      write(s_num, '(i20)') i
      length = 0
      aux = i
      do while (aux > 0)
        aux = aux / 10
        length = length + 1
      end do
      if (mod(length, 2) /= 0) then
        cycle ids
      end if
        

      p = length / 2
      flag = 1
      do q = 20 - (length - 1) + 0, 20 - p
        if (s_num(q + p:q + p) /= s_num(q:q)) then
          flag = 0
          exit
        end if
      end do
      if (flag == 1) then
        ans = ans + i
      end if
      flag = 0
    end do ids
  end do
  print '(i30)', ans

end program part1
