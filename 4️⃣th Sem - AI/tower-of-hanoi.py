def tower_of_hanoi_generalized(n, source, target, auxiliary_towers):
    if n == 0:
        return
    if len(auxiliary_towers) == 0:
        print(f"Move disk {n} from {source} to {target}")
        return
    temp_target = auxiliary_towers[0]
    remaining_auxiliary = auxiliary_towers[1:]
    tower_of_hanoi_generalized(
        n - 1, source, temp_target, remaining_auxiliary + [target]
    )
    print(f"Move disk {n} from {source} to {target}")
    tower_of_hanoi_generalized(
        n - 1, temp_target, target, remaining_auxiliary + [source]
    )


if __name__ == "__main__":
    num_disks = int(input("Enter the number of disks: "))
    num_towers = int(input("Enter the number of towers (minimum 3): "))

    if num_towers < 3:
        print("The number of towers must be at least 3.")
    else:
        towers = [chr(65 + i) for i in range(num_towers)]
        source_tower = towers[0]
        target_tower = towers[1]
        auxiliary_towers = towers[2:]

        tower_of_hanoi_generalized(num_disks, source_tower, target_tower, auxiliary_towers)
