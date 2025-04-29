def tower_of_Hanoi(n, source, target, aux):
    
    global move_count

    if n == 0:
        return

    if len(aux) == 0:
        print(f"Move disk {n} from {source} to {target}")
        move_count += 1
        return

    temp = aux[0]
    rest = aux[1:]

    tower_of_Hanoi(n - 1, source, temp, rest + [target])
    print(f"Move disk {n} from {source} to {target}")
    move_count += 1

    tower_of_Hanoi(n - 1, temp, target, rest + [source])


def main():
    global move_count
    move_count = 0

    n = int(input("Enter number of disks: "))
    k = int(input("Enter towers: "))

    if k < 3:
        print("Minimum 3 towers needed.")
    else:
        towers = [chr(65 + i) for i in range(k)]
        source, target, aux = towers[0], towers[1], towers[2:]
        tower_of_Hanoi(n, source, target, aux)
        print(f"Total moves: {move_count}")


main()