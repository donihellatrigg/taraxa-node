Steps for one account to participate in one round of VRF:

Create secret key:
```bash
$ ../sodium_generate_private_key_from_seed --seed 0000000000000000000000000000000000000000000000000000000000000001
00000000000000000000000000000000000000000000000000000000000000014CB5ABF6AD79FBF5ABBCCAFCC269D85CD2651ED4B885B5869F241AEDF0A5BA29
```

Get signature/proof for message using above key:
```bash
$ ../sodium_get_vrf_proof --message deadbeef \
  --key 00000000000000000000000000000000000000000000000000000000000000014CB5ABF6AD79FBF5ABBCCAFCC269D85CD2651ED4B885B5869F241AEDF0A5BA29
541F7F10FE08F3E26D1EE6F3D3F2430DE6FEA9885D334185256D4F11BDADB6266A2BCB4202BB3A51E6D50368F5977235C6985DE808C3BC3EB76757891E72F736B74EAF08027B9E04621FEA7C4DABC702
```

Get hash of above proof which serves as value for VRF round:
```bash
$ ../sodium_get_vrf_output --proof 541F7F10FE08F3E26D1EE6F3D3F2430DE6FEA9885D334185256D4F11BDADB6266A2BCB4202BB3A51E6D50368F5977235C6985DE808C3BC3EB76757891E72F736B74EAF08027B9E04621FEA7C4DABC702
240962C5C1ECBB6144C7C29058DFD4E236E5E9904DC9CD4F8F414A342515FE5A9106E43125853434869D7FD78AD6371CBE42A8AAA7B82E40D5563CF6CFC04108
```

Output `240962...` serves as this account's value for VRF round corresponding to above message, winner can be e.g. accout whose input has lowest value.