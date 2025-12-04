program part2
  implicit none

  integer(8) :: l, r, i, j, p, q
  integer(8) :: pos
  integer(8) :: ans = 0
  integer(8) :: flag = 0
  integer(8) :: length, aux

  character(len=500) line
  character(len=13) s_l, s_r, s_num
  do i = 1, 13
    s_num = 'x'
  end do
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
    line = line(pos + 1:len(line))
    print *, l, r
    do i = l, r
      write(s_num, '(i13)') i
      length = 0
      aux = i
      do while (aux > 0)
        aux = aux / 10
        length = length + 1
      end do

      period: do p = 1, length - 1
        if (mod(length, p) == 0) then
          flag = 1
          check: do q = 13 - (length - 1) + 0, 13 - length + length - p
            if (s_num(q + p:q + p) /= s_num(q:q)) then
              flag = 0
              exit
            end if
          end do check
          if (flag == 1) then
            exit
          end if
        end if
      end do period
      if (flag == 1) then
        ans = ans + i
      end if
      flag = 0
    end do
  end do
  print '(i30)', ans

end program part2
