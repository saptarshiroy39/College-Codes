def tower_of_hanoi(n, from_rod, to_rod, aux_rod, move_count=0):
    if n == 0:
        return move_count

    if n == 1:
        print(f"Move disk 1 from {from_rod} to {to_rod}")
        return move_count + 1

    move_count = tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod, move_count)
    print(f"Move disk {n} from {from_rod} to {to_rod}")
    move_count += 1

    return tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod, move_count)


num_disks = int(input("Enter the number of disks: "))
num_towers = int(input("Enter the number of towers (minimum 3): "))
if num_towers < 3:
    print("The number of towers must be at least 3.")
    exit()

towers = [chr(65 + i) for i in range(num_towers)]
move_count = tower_of_hanoi(num_disks, towers[0], towers[2], towers[1])
print(f"Total number of moves: {move_count}")