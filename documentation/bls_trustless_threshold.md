Example for creating trustless threshold signature with bls programs based on https://github.com/dashpay/dips/blob/master/dip-0006/bls_m-of-n_threshold_scheme_and_dkg.md

Create trustless 2 out of 3 threshold signature for 3 accounts.

First each account creates their own 2/3 threshold signature from random secret key:

```bash
./bls_make_threshold_keys --A 2 --B 3 --key 0000000000000000000000000000000000000000000000000000000000000001
0000000000000000000000000000000000000000000000000000000000000001 072D33DC96E174CD40EEE68F7CB4E86DD5F8622E66284CB13BD4B504535DF52A 4CF9791126FEBB738BD714AA1E885DBD7A0F3FE09097D69B9FBB6AF71654E114073E2051E8F48B07442C5F2EED7B9310FEDC2E87C00669037ECED2EC8C40BA07
0000000000000000000000000000000000000000000000000000000000000002 0E5A67B92DC2E99A81DDCD1EF969D0DBABF0C45CCC50996277A96A08A6BBEA53 E492D8C836D490C6AEF1D6069143A219F1F0ACAF4A32FB761DB68EECE3398B205368B4D94F5BAFDF9335ED9306C9435CC03CFFDC30509AA71555511E931D1704
0000000000000000000000000000000000000000000000000000000000000003 15879B95C4A45E67C2CCB3AE761EB94981E9268B3278E613B37E1F0CFA19DF7C 5E6394C392C0CF933C22D6A6658202F18AF6FC0454F2DEFCC1C08F7E8929690C98E2ECDD97063C7E9AC13BFEEC702FA1E60CAEA3155C962B75AC751C063F7201
```

```bash
./bls_make_threshold_keys --A 2 --B 3 --key 0000000000000000000000000000000000000000000000000000000000000002
0000000000000000000000000000000000000000000000000000000000000001 18ABF023108831D21A69469DC6C5BB51CADC1ECCE34AE8E9356CC4ACE6C86128 8295FCF077AA469D420854727D279D7180048E4E7D0CF50C931FD1CC50130505360BB735E2C5CDD4C663A01EFEDA047CB6C4F81A0B46BCC73AF3057FB7348B86
0000000000000000000000000000000000000000000000000000000000000002 0C347BC3E11063A27A9E3FBB8D8B769B9618BD99C695D1C1C9D98959CD90C241 F64F77D09BF4A03367E2DAA68A044C07CAC336CF638F8989E97B3AE658F90C037411340F8CBCD59199E514742C41FEAED41D5931EFFDC1DAF650EB36F5B3AE8F
0000000000000000000000000000000000000000000000000000000000000003 24E06BE6F198957495078659545131ED60F4DC66A9E0BAAAFF464E06B4592367 7BCC3EAB393F6F9D0074F8B738805A3498DEC401F66C5E04C93BC44F0C00B302C67FF610413D7283B768576D739B958F8587879FD3841B0993B48495022A559A
```

```bash
./bls_make_threshold_keys --A 2 --B 3 --key 0000000000000000000000000000000000000000000000000000000000000003
0000000000000000000000000000000000000000000000000000000000000001 0CCAA28E5425923F764DC9B4D481AC35C32FE39DC55B1E6FEF78362073FC827E 947097065E479F7F011C9E4B5E4D8525AA5AAF85FB1FEAE2A7805CDC7EB5EA0B0B3FFFF6A3156EC15F0C5593BE7A76D32BC7F8DDD2860009597C1C176FB4EB97
0000000000000000000000000000000000000000000000000000000000000002 1995451CA84B247EEC9B9369A903586B865FC73B8AB63CDFDEF06C40E7F904F9 2D5377900EE130D9FBFE0CF7864FA83923E2B1B3D8C89066713997E0EA0D1E14582CE04CC694260C86A4479D80D5BA8444EA2CEF0A7EBC5C8B080F5A9591A3A1
0000000000000000000000000000000000000000000000000000000000000003 013C8328BC70B6BCA8B50F9E7D85049949F02AD950115B3F2D68A2615BF58767 D8557A5DE68D1EF5EF60840F5AB981F9A2F2E005B6CD381964C8AFD31462F6151F3DAD5AEC32AF7C34CD2DA9F2B503D9A93FAB00C1B5A7B6D1F24052DF582F8E
```

To make notation easier define variables for above outputs:

```bash
export ID1=0000000000000000000000000000000000000000000000000000000000000001
export ID2=0000000000000000000000000000000000000000000000000000000000000002
export ID3=0000000000000000000000000000000000000000000000000000000000000003
```

Data of account 1 (secret and public keys):

```bash
export A1S1=072D33DC96E174CD40EEE68F7CB4E86DD5F8622E66284CB13BD4B504535DF52A
export A1S2=0E5A67B92DC2E99A81DDCD1EF969D0DBABF0C45CCC50996277A96A08A6BBEA53
export A1S3=15879B95C4A45E67C2CCB3AE761EB94981E9268B3278E613B37E1F0CFA19DF7C
export A1P1=4CF9791126FEBB738BD714AA1E885DBD7A0F3FE09097D69B9FBB6AF71654E114073E2051E8F48B07442C5F2EED7B9310FEDC2E87C00669037ECED2EC8C40BA07
export A1P2=E492D8C836D490C6AEF1D6069143A219F1F0ACAF4A32FB761DB68EECE3398B205368B4D94F5BAFDF9335ED9306C9435CC03CFFDC30509AA71555511E931D1704
export A1P3=5E6394C392C0CF933C22D6A6658202F18AF6FC0454F2DEFCC1C08F7E8929690C98E2ECDD97063C7E9AC13BFEEC702FA1E60CAEA3155C962B75AC751C063F7201
```

Account 2:

```bash
export A2S1=18ABF023108831D21A69469DC6C5BB51CADC1ECCE34AE8E9356CC4ACE6C86128
export A2S2=0C347BC3E11063A27A9E3FBB8D8B769B9618BD99C695D1C1C9D98959CD90C241
export A2S3=24E06BE6F198957495078659545131ED60F4DC66A9E0BAAAFF464E06B4592367
export A2P1=8295FCF077AA469D420854727D279D7180048E4E7D0CF50C931FD1CC50130505360BB735E2C5CDD4C663A01EFEDA047CB6C4F81A0B46BCC73AF3057FB7348B86
export A2P2=F64F77D09BF4A03367E2DAA68A044C07CAC336CF638F8989E97B3AE658F90C037411340F8CBCD59199E514742C41FEAED41D5931EFFDC1DAF650EB36F5B3AE8F
export A2P3=7BCC3EAB393F6F9D0074F8B738805A3498DEC401F66C5E04C93BC44F0C00B302C67FF610413D7283B768576D739B958F8587879FD3841B0993B48495022A559A
```

Account 3:

```bash
export A3S1=0CCAA28E5425923F764DC9B4D481AC35C32FE39DC55B1E6FEF78362073FC827E
export A3S2=1995451CA84B247EEC9B9369A903586B865FC73B8AB63CDFDEF06C40E7F904F9
export A3S3=013C8328BC70B6BCA8B50F9E7D85049949F02AD950115B3F2D68A2615BF58767
export A3P1=947097065E479F7F011C9E4B5E4D8525AA5AAF85FB1FEAE2A7805CDC7EB5EA0B0B3FFFF6A3156EC15F0C5593BE7A76D32BC7F8DDD2860009597C1C176FB4EB97
export A3P2=2D5377900EE130D9FBFE0CF7864FA83923E2B1B3D8C89066713997E0EA0D1E14582CE04CC694260C86A4479D80D5BA8444EA2CEF0A7EBC5C8B080F5A9591A3A1
export A3P3=D8557A5DE68D1EF5EF60840F5AB981F9A2F2E005B6CD381964C8AFD31462F6151F3DAD5AEC32AF7C34CD2DA9F2B503D9A93FAB00C1B5A7B6D1F24052DF582F8E
```

Accounts 1, 2 and 3 publish above public keys shares to everyone participating in this setup so everyone can derive every account's public key for trustless threshold:

```bash
./bls_merge_public_keys --id $ID1 --id $ID2 --id $ID3 --pubkey $A1P1 --pubkey $A2P2 --pubkey $A3P3
27428FB8770B04A3DE614F984C36D15FA1B18279CE81E11F0F558011CADCC023DB747EDC61F480443C5C6E71F02209A534852FA51DBD44CD07471E3BDC1B2C0D
```

```bash
./bls_merge_public_keys --id $ID1 --id $ID2 --id $ID3 --pubkey $A3P1 --pubkey $A1P2 --pubkey $A2P3
D5AC2047E406D1B68FFE12C0F70DE252DC6E3EDE01ED50079CDBFD7010BC2A1AA6009E9FBB32C4711F22B48C06F6EB8AC2CE502243D7F07935AB15B1896A0F9B
```

```bash
./bls_merge_public_keys --id $ID1 --id $ID2 --id $ID3 --pubkey $A2P1 --pubkey $A3P2 --pubkey $A1P3
A5308465D01F6C1487A0FB6BD2B0E85BD6D90E748249253650CA06D62FDFBF1DD3E3858D06782C630EE74A4409040C3C14F3210F3B6AB6870493976E0839850B
```

Shorthand for public keys of each account for trustless threshold signature:

```bash
export A1TP=27428FB8770B04A3DE614F984C36D15FA1B18279CE81E11F0F558011CADCC023DB747EDC61F480443C5C6E71F02209A534852FA51DBD44CD07471E3BDC1B2C0D
export A2TP=D5AC2047E406D1B68FFE12C0F70DE252DC6E3EDE01ED50079CDBFD7010BC2A1AA6009E9FBB32C4711F22B48C06F6EB8AC2CE502243D7F07935AB15B1896A0F9B
export A3TP=A5308465D01F6C1487A0FB6BD2B0E85BD6D90E748249253650CA06D62FDFBF1DD3E3858D06782C630EE74A4409040C3C14F3210F3B6AB6870493976E0839850B
```

Each account publishes their public key above from which everyone can derive...

```bash
./bls_merge_public_keys --id $ID1 --id $ID2 --id $ID3 --pubkey $A1TP --pubkey $A2TP --pubkey $A3TP
CBCBE5EE6B32EE82498FA82B59E86EC993D5B1DD95B0C99DE79A918C52CA0312992281927437265466E89C9D87E498A4168AC147182C90CE296C4A12A5C75121
```

...final public key for trustless threshold signature:

```bash
export PUBKEY=CBCBE5EE6B32EE82498FA82B59E86EC993D5B1DD95B0C99DE79A918C52CA0312992281927437265466E89C9D87E498A4168AC147182C90CE296C4A12A5C75121
```

(FIXME: PUBKEY should be identical when combined from any 2 of 3 public keys)

Account 1 sends its secret key share 2 (A1S2) to account 2 in secret and its secret key share 3 (A1S3) to account 3 in secret.
Account 2 sends its secret key share 2 (A2S2) to account 1 in secret and its secret key share 1 (A2S1) to account 3 in secret.
Account 3 sends its secret key share 3 (A3S3) to account 1 in secret and its secret key share 1 (A3S1) to account 2 in secret.
Accounts 1, 2 and 3 each have their own secret key share from one id and two other secret key shares from two other ids.

At this point A1S1 is known only by account 1, A2S3 is known only by account 2 and A3S2 is known only by account 3.

Account 1 creates it's secret key for trustless threshold signature from shares received from accounts 2 and 3:

```bash
./bls_merge_secret_keys --id $ID1 --id $ID2 --id $ID3 --seckey $A1S1 --seckey $A2S2 --seckey $A3S3
174A0FF51DE3EA3EB5DB519A4B015A18092E98972EC8CC1E245A2560ED5D202F
```

Accounts 2 and 3 do the same with their shares:

```bash
./bls_merge_secret_keys --id $ID1 --id $ID2 --id $ID3 --seckey $A3S1 --seckey $A1S2 --seckey $A2S3
20311C6664C08F6372577C1AE598C3FBA6B23A29950049D366B2B24E1C1AEBE8
```

```bash
./bls_merge_secret_keys --id $ID1 --id $ID2 --id $ID3 --seckey $A2S1 --seckey $A3S2 --seckey $A1S3
12CB9CA8FD5B86614C35CD4ACF65E1FC4F5E2D3F3C36EA2FB6F32850F687F409
```

Shorthand for threshold secret shares:

```bash
export A1TS=174A0FF51DE3EA3EB5DB519A4B015A18092E98972EC8CC1E245A2560ED5D202F
export A2TS=20311C6664C08F6372577C1AE598C3FBA6B23A29950049D366B2B24E1C1AEBE8
export A3TS=12CB9CA8FD5B86614C35CD4ACF65E1FC4F5E2D3F3C36EA2FB6F32850F687F409
```

(Check: combining any 2 of 3 secret keys should give identical secret key)

Accounts 1 and 2 create trustless threshold signature:

```bash
./bls_sign_message --message deadbeef --key $A1TS
0E0A549095D3B2395238A622CC82EB6976BD171BC89E071B96DFAF5CBEC85B88
```

```bash
./bls_sign_message --message deadbeef --key $A2TS
6B6BED8D1F58085252B7A6D775482D770D1871168006752FA2F5E7CD2AF1CF15
```

Which can be merged into one:

```bash
./bls_merge_signatures \
  --id $ID1 \
  --id $ID2 \
  --signature 0E0A549095D3B2395238A622CC82EB6976BD171BC89E071B96DFAF5CBEC85B88 \
  --signature 6B6BED8D1F58085252B7A6D775482D770D1871168006752FA2F5E7CD2AF1CF15
1789EC43BECF4DB0A449B0C558F623ABE7952C854AE9FEEFCD891F1BD0B50008
```

And which everyone else can verify using trustless threshold public key:

```bash
...
```