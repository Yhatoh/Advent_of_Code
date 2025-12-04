function valid(i, j) result(flag)
  implicit none
  integer, intent(in) :: i
  integer, intent(in) :: j
  integer :: flag
  if (1 <= i .and. i <= 137 .and. 1 <= j .and. j <= 137) then
    flag = 1
  else
    flag = 0
  end if
end function valid

program part2
  implicit none

  character(len = 137), dimension(137) :: grid
  character(len = 137) :: c
  integer :: i, j, check, l
  integer :: valid, ans

  do i = 1, 137
    read(*, '(a137)') c
    grid(i:i) = c
  end do

  ans = 0
  do l = 1, 137 * 137
    do i = 1, 137
      do j = 1, 137
        check = 0
        if (grid(i)(j:j) == '@') then
          if (valid(i + 1, j) == 1) then
            c = grid(i + 1)
            if (c(j:j) == '@') then
              check = check + 1
            end if
          end if
          if (valid(i - 1, j) == 1) then
            c = grid(i - 1)
            if (c(j:j) == '@') then
              check = check + 1
            end if
          end if
          if (valid(i, j + 1) == 1) then
            c = grid(i)
            if (c(j + 1:j + 1) == '@') then
              check = check + 1
            end if
          end if
          if (valid(i, j - 1) == 1) then
            c = grid(i)
            if (c(j - 1:j - 1) == '@') then
              check = check + 1
            end if
          end if
          if (valid(i + 1, j + 1) == 1) then
            c = grid(i + 1)
            if (c(j + 1:j + 1) == '@') then
              check = check + 1
            end if
          end if
          if (valid(i + 1, j - 1) == 1) then
            c = grid(i + 1)
            if (c(j - 1:j - 1) == '@') then
              check = check + 1
            end if
          end if
          if (valid(i - 1, j - 1) == 1) then
            c = grid(i - 1)
            if (c(j - 1:j - 1) == '@') then
              check = check + 1
            end if
          end if
          if (valid(i - 1, j + 1) == 1) then
            c = grid(i - 1)
            if (c(j + 1:j + 1) == '@') then
              check = check + 1
            end if
          end if
          if (check < 4) then
            ans = ans + 1
            grid(i)(j:j) = '.'
          end if
        end if
      end do
    end do
  end do
  print *, ans
end program part2
