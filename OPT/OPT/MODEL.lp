\ LP format - for model browsing. Use MPS format to capture full model detail.
Minimize
  0 x1_1 + 0 u1 + 0 taxaRateio1_1 + 0 taxaRateio2_2 + 0 taxaRateio3_3
   + 0 taxaRateio4_4 + 0 taxaRateio5_5 + 0 p1 + [ 464 x1_2 * taxaRateio1_2
   + 1330 x1_3 * taxaRateio1_3 + 538 x1_4 * taxaRateio1_4
   + 752 x1_5 * taxaRateio1_5 + 996 x2_1 * taxaRateio2_1
   + 540 x2_3 * taxaRateio2_3 + 952 x2_4 * taxaRateio2_4
   + 592 x2_5 * taxaRateio2_5 + 502 x3_1 * taxaRateio3_1
   + 880 x3_2 * taxaRateio3_2 + 736 x3_4 * taxaRateio3_4
   + 868 x3_5 * taxaRateio3_5 + 1252 x4_1 * taxaRateio4_1
   + 850 x4_2 * taxaRateio4_2 + 536 x4_3 * taxaRateio4_3
   + 1260 x4_5 * taxaRateio4_5 + 840 x5_1 * taxaRateio5_1
   + 500 x5_2 * taxaRateio5_2 + 1042 x5_3 * taxaRateio5_3
   + 1040 x5_4 * taxaRateio5_4 ] / 2 
Subject To
 rest2_cicloIda2: x1_2 + x3_2 + x4_2 + x5_2 <= 1
 rest2_cicloIda3: x1_3 + x2_3 + x4_3 + x5_3 <= 1
 rest2_cicloIda4: x1_4 + x2_4 + x3_4 + x5_4 <= 1
 rest2_cicloIda5: x1_5 + x2_5 + x3_5 + x4_5 <= 1
 rest3_cicloVolta2: x2_1 + x2_3 + x2_4 + x2_5 <= 1
 rest3_cicloVolta3: x3_1 + x3_2 + x3_4 + x3_5 <= 1
 rest3_cicloVolta4: x4_1 + x4_2 + x4_3 + x4_5 <= 1
 rest3_cicloVolta5: x5_1 + x5_2 + x5_3 + x5_4 <= 1
 rest4_origemEm1: x1_2 + x1_3 + x1_4 + x1_5 = 1
 rest5_destinoEm1: x2_1 + x3_1 + x4_1 + x5_1 = 1
 rest6_idaVolta2: x1_2 - x2_1 - x2_3 - x2_4 - x2_5 + x3_2 + x4_2 + x5_2
   = 0
 rest6_idaVolta3: x1_3 + x2_3 - x3_1 - x3_2 - x3_4 - x3_5 + x4_3 + x5_3
   = 0
 rest6_idaVolta4: x1_4 + x2_4 + x3_4 - x4_1 - x4_2 - x4_3 - x4_5 + x5_4
   = 0
 rest6_idaVolta5: x1_5 + x2_5 + x3_5 + x4_5 - x5_1 - x5_2 - x5_3 - x5_4
   = 0
 rest7_evitarSubCiclo2_3: 4 x2_3 + u2 - u3 <= 3
 rest7_evitarSubCiclo2_4: 4 x2_4 + u2 - u4 <= 3
 rest7_evitarSubCiclo2_5: 4 x2_5 + u2 - u5 <= 3
 rest7_evitarSubCiclo3_2: 4 x3_2 - u2 + u3 <= 3
 rest7_evitarSubCiclo3_4: 4 x3_4 + u3 - u4 <= 3
 rest7_evitarSubCiclo3_5: 4 x3_5 + u3 - u5 <= 3
 rest7_evitarSubCiclo4_2: 4 x4_2 - u2 + u4 <= 3
 rest7_evitarSubCiclo4_3: 4 x4_3 - u3 + u4 <= 3
 rest7_evitarSubCiclo4_5: 4 x4_5 + u4 - u5 <= 3
 rest7_evitarSubCiclo5_2: 4 x5_2 - u2 + u5 <= 3
 rest7_evitarSubCiclo5_3: 4 x5_3 - u3 + u5 <= 3
 rest7_evitarSubCiclo5_4: 4 x5_4 - u4 + u5 <= 3
 rest10_carroCapPassandoPelaAresta1_2: - 3 x1_2 + v1_1_2 + v2_1_2 + v3_1_2
   + v4_1_2 + v5_1_2 + v6_1_2 + v7_1_2 + v8_1_2 + v9_1_2 + v10_1_2
   + v11_1_2 + v12_1_2 + v13_1_2 + v14_1_2 + v15_1_2 <= 0
 rest10_carroCapPassandoPelaAresta1_3: - 3 x1_3 + v1_1_3 + v2_1_3 + v3_1_3
   + v4_1_3 + v5_1_3 + v6_1_3 + v7_1_3 + v8_1_3 + v9_1_3 + v10_1_3
   + v11_1_3 + v12_1_3 + v13_1_3 + v14_1_3 + v15_1_3 <= 0
 rest10_carroCapPassandoPelaAresta1_4: - 3 x1_4 + v1_1_4 + v2_1_4 + v3_1_4
   + v4_1_4 + v5_1_4 + v6_1_4 + v7_1_4 + v8_1_4 + v9_1_4 + v10_1_4
   + v11_1_4 + v12_1_4 + v13_1_4 + v14_1_4 + v15_1_4 <= 0
 rest10_carroCapPassandoPelaAresta1_5: - 3 x1_5 + v1_1_5 + v2_1_5 + v3_1_5
   + v4_1_5 + v5_1_5 + v6_1_5 + v7_1_5 + v8_1_5 + v9_1_5 + v10_1_5
   + v11_1_5 + v12_1_5 + v13_1_5 + v14_1_5 + v15_1_5 <= 0
 rest10_carroCapPassandoPelaAresta2_1: - 3 x2_1 + v1_2_1 + v2_2_1 + v3_2_1
   + v4_2_1 + v5_2_1 + v6_2_1 + v7_2_1 + v8_2_1 + v9_2_1 + v10_2_1
   + v11_2_1 + v12_2_1 + v13_2_1 + v14_2_1 + v15_2_1 <= 0
 rest10_carroCapPassandoPelaAresta2_3: - 3 x2_3 + v1_2_3 + v2_2_3 + v3_2_3
   + v4_2_3 + v5_2_3 + v6_2_3 + v7_2_3 + v8_2_3 + v9_2_3 + v10_2_3
   + v11_2_3 + v12_2_3 + v13_2_3 + v14_2_3 + v15_2_3 <= 0
 rest10_carroCapPassandoPelaAresta2_4: - 3 x2_4 + v1_2_4 + v2_2_4 + v3_2_4
   + v4_2_4 + v5_2_4 + v6_2_4 + v7_2_4 + v8_2_4 + v9_2_4 + v10_2_4
   + v11_2_4 + v12_2_4 + v13_2_4 + v14_2_4 + v15_2_4 <= 0
 rest10_carroCapPassandoPelaAresta2_5: - 3 x2_5 + v1_2_5 + v2_2_5 + v3_2_5
   + v4_2_5 + v5_2_5 + v6_2_5 + v7_2_5 + v8_2_5 + v9_2_5 + v10_2_5
   + v11_2_5 + v12_2_5 + v13_2_5 + v14_2_5 + v15_2_5 <= 0
 rest10_carroCapPassandoPelaAresta3_1: - 3 x3_1 + v1_3_1 + v2_3_1 + v3_3_1
   + v4_3_1 + v5_3_1 + v6_3_1 + v7_3_1 + v8_3_1 + v9_3_1 + v10_3_1
   + v11_3_1 + v12_3_1 + v13_3_1 + v14_3_1 + v15_3_1 <= 0
 rest10_carroCapPassandoPelaAresta3_2: - 3 x3_2 + v1_3_2 + v2_3_2 + v3_3_2
   + v4_3_2 + v5_3_2 + v6_3_2 + v7_3_2 + v8_3_2 + v9_3_2 + v10_3_2
   + v11_3_2 + v12_3_2 + v13_3_2 + v14_3_2 + v15_3_2 <= 0
 rest10_carroCapPassandoPelaAresta3_4: - 3 x3_4 + v1_3_4 + v2_3_4 + v3_3_4
   + v4_3_4 + v5_3_4 + v6_3_4 + v7_3_4 + v8_3_4 + v9_3_4 + v10_3_4
   + v11_3_4 + v12_3_4 + v13_3_4 + v14_3_4 + v15_3_4 <= 0
 rest10_carroCapPassandoPelaAresta3_5: - 3 x3_5 + v1_3_5 + v2_3_5 + v3_3_5
   + v4_3_5 + v5_3_5 + v6_3_5 + v7_3_5 + v8_3_5 + v9_3_5 + v10_3_5
   + v11_3_5 + v12_3_5 + v13_3_5 + v14_3_5 + v15_3_5 <= 0
 rest10_carroCapPassandoPelaAresta4_1: - 3 x4_1 + v1_4_1 + v2_4_1 + v3_4_1
   + v4_4_1 + v5_4_1 + v6_4_1 + v7_4_1 + v8_4_1 + v9_4_1 + v10_4_1
   + v11_4_1 + v12_4_1 + v13_4_1 + v14_4_1 + v15_4_1 <= 0
 rest10_carroCapPassandoPelaAresta4_2: - 3 x4_2 + v1_4_2 + v2_4_2 + v3_4_2
   + v4_4_2 + v5_4_2 + v6_4_2 + v7_4_2 + v8_4_2 + v9_4_2 + v10_4_2
   + v11_4_2 + v12_4_2 + v13_4_2 + v14_4_2 + v15_4_2 <= 0
 rest10_carroCapPassandoPelaAresta4_3: - 3 x4_3 + v1_4_3 + v2_4_3 + v3_4_3
   + v4_4_3 + v5_4_3 + v6_4_3 + v7_4_3 + v8_4_3 + v9_4_3 + v10_4_3
   + v11_4_3 + v12_4_3 + v13_4_3 + v14_4_3 + v15_4_3 <= 0
 rest10_carroCapPassandoPelaAresta4_5: - 3 x4_5 + v1_4_5 + v2_4_5 + v3_4_5
   + v4_4_5 + v5_4_5 + v6_4_5 + v7_4_5 + v8_4_5 + v9_4_5 + v10_4_5
   + v11_4_5 + v12_4_5 + v13_4_5 + v14_4_5 + v15_4_5 <= 0
 rest10_carroCapPassandoPelaAresta5_1: - 3 x5_1 + v1_5_1 + v2_5_1 + v3_5_1
   + v4_5_1 + v5_5_1 + v6_5_1 + v7_5_1 + v8_5_1 + v9_5_1 + v10_5_1
   + v11_5_1 + v12_5_1 + v13_5_1 + v14_5_1 + v15_5_1 <= 0
 rest10_carroCapPassandoPelaAresta5_2: - 3 x5_2 + v1_5_2 + v2_5_2 + v3_5_2
   + v4_5_2 + v5_5_2 + v6_5_2 + v7_5_2 + v8_5_2 + v9_5_2 + v10_5_2
   + v11_5_2 + v12_5_2 + v13_5_2 + v14_5_2 + v15_5_2 <= 0
 rest10_carroCapPassandoPelaAresta5_3: - 3 x5_3 + v1_5_3 + v2_5_3 + v3_5_3
   + v4_5_3 + v5_5_3 + v6_5_3 + v7_5_3 + v8_5_3 + v9_5_3 + v10_5_3
   + v11_5_3 + v12_5_3 + v13_5_3 + v14_5_3 + v15_5_3 <= 0
 rest10_carroCapPassandoPelaAresta5_4: - 3 x5_4 + v1_5_4 + v2_5_4 + v3_5_4
   + v4_5_4 + v5_5_4 + v6_5_4 + v7_5_4 + v8_5_4 + v9_5_4 + v10_5_4
   + v11_5_4 + v12_5_4 + v13_5_4 + v14_5_4 + v15_5_4 <= 0
 rest11_passageiroDesembarcaSoUmaVez1: f1_1 + f1_2 + f1_3 + f1_4 + f1_5
   <= 1
 rest11_passageiroDesembarcaSoUmaVez2: f2_1 + f2_2 + f2_3 + f2_4 + f2_5
   <= 1
 rest11_passageiroDesembarcaSoUmaVez3: f3_1 + f3_2 + f3_3 + f3_4 + f3_5
   <= 1
 rest11_passageiroDesembarcaSoUmaVez4: f4_1 + f4_2 + f4_3 + f4_4 + f4_5
   <= 1
 rest11_passageiroDesembarcaSoUmaVez5: f5_1 + f5_2 + f5_3 + f5_4 + f5_5
   <= 1
 rest11_passageiroDesembarcaSoUmaVez6: f6_1 + f6_2 + f6_3 + f6_4 + f6_5
   <= 1
 rest11_passageiroDesembarcaSoUmaVez7: f7_1 + f7_2 + f7_3 + f7_4 + f7_5
   <= 1
 rest11_passageiroDesembarcaSoUmaVez8: f8_1 + f8_2 + f8_3 + f8_4 + f8_5
   <= 1
 rest11_passageiroDesembarcaSoUmaVez9: f9_1 + f9_2 + f9_3 + f9_4 + f9_5
   <= 1
 rest11_passageiroDesembarcaSoUmaVez10: f10_1 + f10_2 + f10_3 + f10_4
   + f10_5 <= 1
 rest11_passageiroDesembarcaSoUmaVez11: f11_1 + f11_2 + f11_3 + f11_4
   + f11_5 <= 1
 rest11_passageiroDesembarcaSoUmaVez12: f12_1 + f12_2 + f12_3 + f12_4
   + f12_5 <= 1
 rest11_passageiroDesembarcaSoUmaVez13: f13_1 + f13_2 + f13_3 + f13_4
   + f13_5 <= 1
 rest11_passageiroDesembarcaSoUmaVez14: f14_1 + f14_2 + f14_3 + f14_4
   + f14_5 <= 1
 rest11_passageiroDesembarcaSoUmaVez15: f15_1 + f15_2 + f15_3 + f15_4
   + f15_5 <= 1
 rest14_passageiroNaoDesembarcaNaSuaOrigem1: f1_1 = 0
 rest14_passageiroNaoDesembarcaNaSuaOrigem2: f2_1 = 0
 rest14_passageiroNaoDesembarcaNaSuaOrigem3: f3_1 = 0
 rest14_passageiroNaoDesembarcaNaSuaOrigem4: f4_2 = 0
 rest14_passageiroNaoDesembarcaNaSuaOrigem5: f5_2 = 0
 rest14_passageiroNaoDesembarcaNaSuaOrigem6: f6_2 = 0
 rest14_passageiroNaoDesembarcaNaSuaOrigem7: f7_3 = 0
 rest14_passageiroNaoDesembarcaNaSuaOrigem8: f8_3 = 0
 rest14_passageiroNaoDesembarcaNaSuaOrigem9: f9_3 = 0
 rest14_passageiroNaoDesembarcaNaSuaOrigem10: f10_4 = 0
 rest14_passageiroNaoDesembarcaNaSuaOrigem11: f11_4 = 0
 rest14_passageiroNaoDesembarcaNaSuaOrigem12: f12_4 = 0
 rest14_passageiroNaoDesembarcaNaSuaOrigem13: f13_5 = 0
 rest14_passageiroNaoDesembarcaNaSuaOrigem14: f14_5 = 0
 rest14_passageiroNaoDesembarcaNaSuaOrigem15: f15_5 = 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_1_1: - q1 + v1_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_1_2: - q1 + v1_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_1_3: - q1 + v1_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_1_4: - q1 + v1_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_1_5: - q1 + v1_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_2_1: - q1 + v1_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_2_2: - q1 + v1_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_2_3: - q1 + v1_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_2_4: - q1 + v1_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_2_5: - q1 + v1_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_3_1: - q1 + v1_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_3_2: - q1 + v1_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_3_3: - q1 + v1_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_3_4: - q1 + v1_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_3_5: - q1 + v1_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_4_1: - q1 + v1_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_4_2: - q1 + v1_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_4_3: - q1 + v1_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_4_4: - q1 + v1_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_4_5: - q1 + v1_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_5_1: - q1 + v1_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_5_2: - q1 + v1_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_5_3: - q1 + v1_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_5_4: - q1 + v1_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo1_5_5: - q1 + v1_5_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_1_1: - q2 + v2_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_1_2: - q2 + v2_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_1_3: - q2 + v2_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_1_4: - q2 + v2_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_1_5: - q2 + v2_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_2_1: - q2 + v2_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_2_2: - q2 + v2_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_2_3: - q2 + v2_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_2_4: - q2 + v2_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_2_5: - q2 + v2_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_3_1: - q2 + v2_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_3_2: - q2 + v2_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_3_3: - q2 + v2_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_3_4: - q2 + v2_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_3_5: - q2 + v2_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_4_1: - q2 + v2_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_4_2: - q2 + v2_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_4_3: - q2 + v2_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_4_4: - q2 + v2_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_4_5: - q2 + v2_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_5_1: - q2 + v2_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_5_2: - q2 + v2_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_5_3: - q2 + v2_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_5_4: - q2 + v2_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo2_5_5: - q2 + v2_5_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_1_1: - q3 + v3_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_1_2: - q3 + v3_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_1_3: - q3 + v3_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_1_4: - q3 + v3_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_1_5: - q3 + v3_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_2_1: - q3 + v3_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_2_2: - q3 + v3_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_2_3: - q3 + v3_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_2_4: - q3 + v3_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_2_5: - q3 + v3_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_3_1: - q3 + v3_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_3_2: - q3 + v3_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_3_3: - q3 + v3_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_3_4: - q3 + v3_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_3_5: - q3 + v3_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_4_1: - q3 + v3_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_4_2: - q3 + v3_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_4_3: - q3 + v3_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_4_4: - q3 + v3_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_4_5: - q3 + v3_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_5_1: - q3 + v3_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_5_2: - q3 + v3_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_5_3: - q3 + v3_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_5_4: - q3 + v3_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo3_5_5: - q3 + v3_5_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_1_1: - q4 + v4_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_1_2: - q4 + v4_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_1_3: - q4 + v4_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_1_4: - q4 + v4_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_1_5: - q4 + v4_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_2_1: - q4 + v4_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_2_2: - q4 + v4_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_2_3: - q4 + v4_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_2_4: - q4 + v4_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_2_5: - q4 + v4_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_3_1: - q4 + v4_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_3_2: - q4 + v4_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_3_3: - q4 + v4_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_3_4: - q4 + v4_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_3_5: - q4 + v4_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_4_1: - q4 + v4_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_4_2: - q4 + v4_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_4_3: - q4 + v4_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_4_4: - q4 + v4_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_4_5: - q4 + v4_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_5_1: - q4 + v4_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_5_2: - q4 + v4_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_5_3: - q4 + v4_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_5_4: - q4 + v4_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo4_5_5: - q4 + v4_5_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_1_1: - q5 + v5_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_1_2: - q5 + v5_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_1_3: - q5 + v5_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_1_4: - q5 + v5_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_1_5: - q5 + v5_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_2_1: - q5 + v5_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_2_2: - q5 + v5_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_2_3: - q5 + v5_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_2_4: - q5 + v5_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_2_5: - q5 + v5_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_3_1: - q5 + v5_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_3_2: - q5 + v5_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_3_3: - q5 + v5_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_3_4: - q5 + v5_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_3_5: - q5 + v5_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_4_1: - q5 + v5_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_4_2: - q5 + v5_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_4_3: - q5 + v5_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_4_4: - q5 + v5_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_4_5: - q5 + v5_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_5_1: - q5 + v5_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_5_2: - q5 + v5_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_5_3: - q5 + v5_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_5_4: - q5 + v5_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo5_5_5: - q5 + v5_5_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_1_1: - q6 + v6_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_1_2: - q6 + v6_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_1_3: - q6 + v6_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_1_4: - q6 + v6_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_1_5: - q6 + v6_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_2_1: - q6 + v6_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_2_2: - q6 + v6_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_2_3: - q6 + v6_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_2_4: - q6 + v6_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_2_5: - q6 + v6_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_3_1: - q6 + v6_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_3_2: - q6 + v6_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_3_3: - q6 + v6_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_3_4: - q6 + v6_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_3_5: - q6 + v6_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_4_1: - q6 + v6_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_4_2: - q6 + v6_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_4_3: - q6 + v6_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_4_4: - q6 + v6_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_4_5: - q6 + v6_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_5_1: - q6 + v6_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_5_2: - q6 + v6_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_5_3: - q6 + v6_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_5_4: - q6 + v6_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo6_5_5: - q6 + v6_5_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_1_1: - q7 + v7_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_1_2: - q7 + v7_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_1_3: - q7 + v7_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_1_4: - q7 + v7_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_1_5: - q7 + v7_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_2_1: - q7 + v7_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_2_2: - q7 + v7_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_2_3: - q7 + v7_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_2_4: - q7 + v7_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_2_5: - q7 + v7_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_3_1: - q7 + v7_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_3_2: - q7 + v7_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_3_3: - q7 + v7_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_3_4: - q7 + v7_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_3_5: - q7 + v7_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_4_1: - q7 + v7_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_4_2: - q7 + v7_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_4_3: - q7 + v7_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_4_4: - q7 + v7_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_4_5: - q7 + v7_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_5_1: - q7 + v7_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_5_2: - q7 + v7_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_5_3: - q7 + v7_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_5_4: - q7 + v7_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo7_5_5: - q7 + v7_5_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_1_1: - q8 + v8_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_1_2: - q8 + v8_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_1_3: - q8 + v8_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_1_4: - q8 + v8_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_1_5: - q8 + v8_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_2_1: - q8 + v8_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_2_2: - q8 + v8_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_2_3: - q8 + v8_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_2_4: - q8 + v8_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_2_5: - q8 + v8_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_3_1: - q8 + v8_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_3_2: - q8 + v8_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_3_3: - q8 + v8_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_3_4: - q8 + v8_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_3_5: - q8 + v8_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_4_1: - q8 + v8_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_4_2: - q8 + v8_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_4_3: - q8 + v8_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_4_4: - q8 + v8_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_4_5: - q8 + v8_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_5_1: - q8 + v8_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_5_2: - q8 + v8_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_5_3: - q8 + v8_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_5_4: - q8 + v8_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo8_5_5: - q8 + v8_5_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_1_1: - q9 + v9_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_1_2: - q9 + v9_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_1_3: - q9 + v9_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_1_4: - q9 + v9_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_1_5: - q9 + v9_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_2_1: - q9 + v9_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_2_2: - q9 + v9_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_2_3: - q9 + v9_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_2_4: - q9 + v9_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_2_5: - q9 + v9_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_3_1: - q9 + v9_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_3_2: - q9 + v9_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_3_3: - q9 + v9_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_3_4: - q9 + v9_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_3_5: - q9 + v9_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_4_1: - q9 + v9_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_4_2: - q9 + v9_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_4_3: - q9 + v9_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_4_4: - q9 + v9_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_4_5: - q9 + v9_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_5_1: - q9 + v9_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_5_2: - q9 + v9_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_5_3: - q9 + v9_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_5_4: - q9 + v9_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo9_5_5: - q9 + v9_5_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_1_1: - q10 + v10_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_1_2: - q10 + v10_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_1_3: - q10 + v10_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_1_4: - q10 + v10_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_1_5: - q10 + v10_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_2_1: - q10 + v10_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_2_2: - q10 + v10_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_2_3: - q10 + v10_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_2_4: - q10 + v10_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_2_5: - q10 + v10_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_3_1: - q10 + v10_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_3_2: - q10 + v10_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_3_3: - q10 + v10_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_3_4: - q10 + v10_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_3_5: - q10 + v10_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_4_1: - q10 + v10_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_4_2: - q10 + v10_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_4_3: - q10 + v10_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_4_4: - q10 + v10_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_4_5: - q10 + v10_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_5_1: - q10 + v10_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_5_2: - q10 + v10_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_5_3: - q10 + v10_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_5_4: - q10 + v10_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo10_5_5: - q10 + v10_5_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_1_1: - q11 + v11_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_1_2: - q11 + v11_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_1_3: - q11 + v11_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_1_4: - q11 + v11_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_1_5: - q11 + v11_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_2_1: - q11 + v11_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_2_2: - q11 + v11_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_2_3: - q11 + v11_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_2_4: - q11 + v11_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_2_5: - q11 + v11_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_3_1: - q11 + v11_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_3_2: - q11 + v11_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_3_3: - q11 + v11_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_3_4: - q11 + v11_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_3_5: - q11 + v11_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_4_1: - q11 + v11_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_4_2: - q11 + v11_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_4_3: - q11 + v11_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_4_4: - q11 + v11_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_4_5: - q11 + v11_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_5_1: - q11 + v11_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_5_2: - q11 + v11_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_5_3: - q11 + v11_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_5_4: - q11 + v11_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo11_5_5: - q11 + v11_5_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_1_1: - q12 + v12_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_1_2: - q12 + v12_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_1_3: - q12 + v12_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_1_4: - q12 + v12_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_1_5: - q12 + v12_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_2_1: - q12 + v12_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_2_2: - q12 + v12_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_2_3: - q12 + v12_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_2_4: - q12 + v12_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_2_5: - q12 + v12_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_3_1: - q12 + v12_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_3_2: - q12 + v12_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_3_3: - q12 + v12_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_3_4: - q12 + v12_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_3_5: - q12 + v12_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_4_1: - q12 + v12_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_4_2: - q12 + v12_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_4_3: - q12 + v12_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_4_4: - q12 + v12_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_4_5: - q12 + v12_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_5_1: - q12 + v12_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_5_2: - q12 + v12_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_5_3: - q12 + v12_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_5_4: - q12 + v12_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo12_5_5: - q12 + v12_5_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_1_1: - q13 + v13_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_1_2: - q13 + v13_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_1_3: - q13 + v13_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_1_4: - q13 + v13_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_1_5: - q13 + v13_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_2_1: - q13 + v13_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_2_2: - q13 + v13_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_2_3: - q13 + v13_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_2_4: - q13 + v13_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_2_5: - q13 + v13_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_3_1: - q13 + v13_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_3_2: - q13 + v13_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_3_3: - q13 + v13_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_3_4: - q13 + v13_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_3_5: - q13 + v13_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_4_1: - q13 + v13_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_4_2: - q13 + v13_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_4_3: - q13 + v13_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_4_4: - q13 + v13_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_4_5: - q13 + v13_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_5_1: - q13 + v13_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_5_2: - q13 + v13_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_5_3: - q13 + v13_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_5_4: - q13 + v13_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo13_5_5: - q13 + v13_5_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_1_1: - q14 + v14_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_1_2: - q14 + v14_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_1_3: - q14 + v14_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_1_4: - q14 + v14_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_1_5: - q14 + v14_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_2_1: - q14 + v14_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_2_2: - q14 + v14_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_2_3: - q14 + v14_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_2_4: - q14 + v14_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_2_5: - q14 + v14_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_3_1: - q14 + v14_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_3_2: - q14 + v14_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_3_3: - q14 + v14_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_3_4: - q14 + v14_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_3_5: - q14 + v14_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_4_1: - q14 + v14_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_4_2: - q14 + v14_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_4_3: - q14 + v14_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_4_4: - q14 + v14_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_4_5: - q14 + v14_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_5_1: - q14 + v14_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_5_2: - q14 + v14_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_5_3: - q14 + v14_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_5_4: - q14 + v14_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo14_5_5: - q14 + v14_5_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_1_1: - q15 + v15_1_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_1_2: - q15 + v15_1_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_1_3: - q15 + v15_1_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_1_4: - q15 + v15_1_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_1_5: - q15 + v15_1_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_2_1: - q15 + v15_2_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_2_2: - q15 + v15_2_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_2_3: - q15 + v15_2_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_2_4: - q15 + v15_2_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_2_5: - q15 + v15_2_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_3_1: - q15 + v15_3_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_3_2: - q15 + v15_3_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_3_3: - q15 + v15_3_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_3_4: - q15 + v15_3_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_3_5: - q15 + v15_3_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_4_1: - q15 + v15_4_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_4_2: - q15 + v15_4_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_4_3: - q15 + v15_4_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_4_4: - q15 + v15_4_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_4_5: - q15 + v15_4_5 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_5_1: - q15 + v15_5_1 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_5_2: - q15 + v15_5_2 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_5_3: - q15 + v15_5_3 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_5_4: - q15 + v15_5_4 <= 0
 rest15_soPassaPassageiroPorOndePassaVeiculo15_5_5: - q15 + v15_5_5 <= 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque1: - q1 + f1_1 + f1_2
   + f1_3 + f1_4 + f1_5 = 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque2: - q2 + f2_1 + f2_2
   + f2_3 + f2_4 + f2_5 = 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque3: - q3 + f3_1 + f3_2
   + f3_3 + f3_4 + f3_5 = 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque4: - q4 + f4_1 + f4_2
   + f4_3 + f4_4 + f4_5 = 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque5: - q5 + f5_1 + f5_2
   + f5_3 + f5_4 + f5_5 = 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque6: - q6 + f6_1 + f6_2
   + f6_3 + f6_4 + f6_5 = 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque7: - q7 + f7_1 + f7_2
   + f7_3 + f7_4 + f7_5 = 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque8: - q8 + f8_1 + f8_2
   + f8_3 + f8_4 + f8_5 = 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque9: - q9 + f9_1 + f9_2
   + f9_3 + f9_4 + f9_5 = 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque10: - q10 + f10_1 + f10_2
   + f10_3 + f10_4 + f10_5 = 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque11: - q11 + f11_1 + f11_2
   + f11_3 + f11_4 + f11_5 = 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque12: - q12 + f12_1 + f12_2
   + f12_3 + f12_4 + f12_5 = 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque13: - q13 + f13_1 + f13_2
   + f13_3 + f13_4 + f13_5 = 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque14: - q14 + f14_1 + f14_2
   + f14_3 + f14_4 + f14_5 = 0
 rest17_SePassageiroEmbarcaEntaoForcaDesembarque15: - q15 + f15_1 + f15_2
   + f15_3 + f15_4 + f15_5 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem1: - q1 + v1_1_2 + v1_1_3
   + v1_1_4 + v1_1_5 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem2: - q2 + v2_1_2 + v2_1_3
   + v2_1_4 + v2_1_5 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem3: - q3 + v3_1_2 + v3_1_3
   + v3_1_4 + v3_1_5 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem4: - q4 + v4_2_1 + v4_2_3
   + v4_2_4 + v4_2_5 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem5: - q5 + v5_2_1 + v5_2_3
   + v5_2_4 + v5_2_5 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem6: - q6 + v6_2_1 + v6_2_3
   + v6_2_4 + v6_2_5 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem7: - q7 + v7_3_1 + v7_3_2
   + v7_3_4 + v7_3_5 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem8: - q8 + v8_3_1 + v8_3_2
   + v8_3_4 + v8_3_5 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem9: - q9 + v9_3_1 + v9_3_2
   + v9_3_4 + v9_3_5 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem10: - q10 + v10_4_1 + v10_4_2
   + v10_4_3 + v10_4_5 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem11: - q11 + v11_4_1 + v11_4_2
   + v11_4_3 + v11_4_5 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem12: - q12 + v12_4_1 + v12_4_2
   + v12_4_3 + v12_4_5 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem13: - q13 + v13_5_1 + v13_5_2
   + v13_5_3 + v13_5_4 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem14: - q14 + v14_5_1 + v14_5_2
   + v14_5_3 + v14_5_4 = 0
 rest18_PassageiroEhEmbarcadoApenasNaOrigem15: - q15 + v15_5_1 + v15_5_2
   + v15_5_3 + v15_5_4 = 0
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo1_1: f1_1 + v1_1_1 + v1_1_2
   + v1_1_3 + v1_1_4 + v1_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo1_2: f1_2 + v1_2_1 + v1_2_2
   + v1_2_3 + v1_2_4 + v1_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo1_3: f1_3 + v1_3_1 + v1_3_2
   + v1_3_3 + v1_3_4 + v1_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo1_4: f1_4 + v1_4_1 + v1_4_2
   + v1_4_3 + v1_4_4 + v1_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo1_5: f1_5 + v1_5_1 + v1_5_2
   + v1_5_3 + v1_5_4 + v1_5_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo2_1: f2_1 + v2_1_1 + v2_1_2
   + v2_1_3 + v2_1_4 + v2_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo2_2: f2_2 + v2_2_1 + v2_2_2
   + v2_2_3 + v2_2_4 + v2_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo2_3: f2_3 + v2_3_1 + v2_3_2
   + v2_3_3 + v2_3_4 + v2_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo2_4: f2_4 + v2_4_1 + v2_4_2
   + v2_4_3 + v2_4_4 + v2_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo2_5: f2_5 + v2_5_1 + v2_5_2
   + v2_5_3 + v2_5_4 + v2_5_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo3_1: f3_1 + v3_1_1 + v3_1_2
   + v3_1_3 + v3_1_4 + v3_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo3_2: f3_2 + v3_2_1 + v3_2_2
   + v3_2_3 + v3_2_4 + v3_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo3_3: f3_3 + v3_3_1 + v3_3_2
   + v3_3_3 + v3_3_4 + v3_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo3_4: f3_4 + v3_4_1 + v3_4_2
   + v3_4_3 + v3_4_4 + v3_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo3_5: f3_5 + v3_5_1 + v3_5_2
   + v3_5_3 + v3_5_4 + v3_5_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo4_1: f4_1 + v4_1_1 + v4_1_2
   + v4_1_3 + v4_1_4 + v4_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo4_2: f4_2 + v4_2_1 + v4_2_2
   + v4_2_3 + v4_2_4 + v4_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo4_3: f4_3 + v4_3_1 + v4_3_2
   + v4_3_3 + v4_3_4 + v4_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo4_4: f4_4 + v4_4_1 + v4_4_2
   + v4_4_3 + v4_4_4 + v4_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo4_5: f4_5 + v4_5_1 + v4_5_2
   + v4_5_3 + v4_5_4 + v4_5_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo5_1: f5_1 + v5_1_1 + v5_1_2
   + v5_1_3 + v5_1_4 + v5_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo5_2: f5_2 + v5_2_1 + v5_2_2
   + v5_2_3 + v5_2_4 + v5_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo5_3: f5_3 + v5_3_1 + v5_3_2
   + v5_3_3 + v5_3_4 + v5_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo5_4: f5_4 + v5_4_1 + v5_4_2
   + v5_4_3 + v5_4_4 + v5_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo5_5: f5_5 + v5_5_1 + v5_5_2
   + v5_5_3 + v5_5_4 + v5_5_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo6_1: f6_1 + v6_1_1 + v6_1_2
   + v6_1_3 + v6_1_4 + v6_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo6_2: f6_2 + v6_2_1 + v6_2_2
   + v6_2_3 + v6_2_4 + v6_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo6_3: f6_3 + v6_3_1 + v6_3_2
   + v6_3_3 + v6_3_4 + v6_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo6_4: f6_4 + v6_4_1 + v6_4_2
   + v6_4_3 + v6_4_4 + v6_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo6_5: f6_5 + v6_5_1 + v6_5_2
   + v6_5_3 + v6_5_4 + v6_5_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo7_1: f7_1 + v7_1_1 + v7_1_2
   + v7_1_3 + v7_1_4 + v7_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo7_2: f7_2 + v7_2_1 + v7_2_2
   + v7_2_3 + v7_2_4 + v7_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo7_3: f7_3 + v7_3_1 + v7_3_2
   + v7_3_3 + v7_3_4 + v7_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo7_4: f7_4 + v7_4_1 + v7_4_2
   + v7_4_3 + v7_4_4 + v7_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo7_5: f7_5 + v7_5_1 + v7_5_2
   + v7_5_3 + v7_5_4 + v7_5_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo8_1: f8_1 + v8_1_1 + v8_1_2
   + v8_1_3 + v8_1_4 + v8_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo8_2: f8_2 + v8_2_1 + v8_2_2
   + v8_2_3 + v8_2_4 + v8_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo8_3: f8_3 + v8_3_1 + v8_3_2
   + v8_3_3 + v8_3_4 + v8_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo8_4: f8_4 + v8_4_1 + v8_4_2
   + v8_4_3 + v8_4_4 + v8_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo8_5: f8_5 + v8_5_1 + v8_5_2
   + v8_5_3 + v8_5_4 + v8_5_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo9_1: f9_1 + v9_1_1 + v9_1_2
   + v9_1_3 + v9_1_4 + v9_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo9_2: f9_2 + v9_2_1 + v9_2_2
   + v9_2_3 + v9_2_4 + v9_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo9_3: f9_3 + v9_3_1 + v9_3_2
   + v9_3_3 + v9_3_4 + v9_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo9_4: f9_4 + v9_4_1 + v9_4_2
   + v9_4_3 + v9_4_4 + v9_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo9_5: f9_5 + v9_5_1 + v9_5_2
   + v9_5_3 + v9_5_4 + v9_5_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo10_1: f10_1 + v10_1_1
   + v10_1_2 + v10_1_3 + v10_1_4 + v10_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo10_2: f10_2 + v10_2_1
   + v10_2_2 + v10_2_3 + v10_2_4 + v10_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo10_3: f10_3 + v10_3_1
   + v10_3_2 + v10_3_3 + v10_3_4 + v10_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo10_4: f10_4 + v10_4_1
   + v10_4_2 + v10_4_3 + v10_4_4 + v10_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo10_5: f10_5 + v10_5_1
   + v10_5_2 + v10_5_3 + v10_5_4 + v10_5_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo11_1: f11_1 + v11_1_1
   + v11_1_2 + v11_1_3 + v11_1_4 + v11_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo11_2: f11_2 + v11_2_1
   + v11_2_2 + v11_2_3 + v11_2_4 + v11_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo11_3: f11_3 + v11_3_1
   + v11_3_2 + v11_3_3 + v11_3_4 + v11_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo11_4: f11_4 + v11_4_1
   + v11_4_2 + v11_4_3 + v11_4_4 + v11_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo11_5: f11_5 + v11_5_1
   + v11_5_2 + v11_5_3 + v11_5_4 + v11_5_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo12_1: f12_1 + v12_1_1
   + v12_1_2 + v12_1_3 + v12_1_4 + v12_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo12_2: f12_2 + v12_2_1
   + v12_2_2 + v12_2_3 + v12_2_4 + v12_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo12_3: f12_3 + v12_3_1
   + v12_3_2 + v12_3_3 + v12_3_4 + v12_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo12_4: f12_4 + v12_4_1
   + v12_4_2 + v12_4_3 + v12_4_4 + v12_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo12_5: f12_5 + v12_5_1
   + v12_5_2 + v12_5_3 + v12_5_4 + v12_5_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo13_1: f13_1 + v13_1_1
   + v13_1_2 + v13_1_3 + v13_1_4 + v13_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo13_2: f13_2 + v13_2_1
   + v13_2_2 + v13_2_3 + v13_2_4 + v13_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo13_3: f13_3 + v13_3_1
   + v13_3_2 + v13_3_3 + v13_3_4 + v13_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo13_4: f13_4 + v13_4_1
   + v13_4_2 + v13_4_3 + v13_4_4 + v13_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo13_5: f13_5 + v13_5_1
   + v13_5_2 + v13_5_3 + v13_5_4 + v13_5_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo14_1: f14_1 + v14_1_1
   + v14_1_2 + v14_1_3 + v14_1_4 + v14_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo14_2: f14_2 + v14_2_1
   + v14_2_2 + v14_2_3 + v14_2_4 + v14_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo14_3: f14_3 + v14_3_1
   + v14_3_2 + v14_3_3 + v14_3_4 + v14_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo14_4: f14_4 + v14_4_1
   + v14_4_2 + v14_4_3 + v14_4_4 + v14_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo14_5: f14_5 + v14_5_1
   + v14_5_2 + v14_5_3 + v14_5_4 + v14_5_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo15_1: f15_1 + v15_1_1
   + v15_1_2 + v15_1_3 + v15_1_4 + v15_1_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo15_2: f15_2 + v15_2_1
   + v15_2_2 + v15_2_3 + v15_2_4 + v15_2_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo15_3: f15_3 + v15_3_1
   + v15_3_2 + v15_3_3 + v15_3_4 + v15_3_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo15_4: f15_4 + v15_4_1
   + v15_4_2 + v15_4_3 + v15_4_4 + v15_4_5 <= 1
 rest19_passageiroEmbarcadoNaoDesembarcaDeNovo15_5: f15_5 + v15_5_1
   + v15_5_2 + v15_5_3 + v15_5_4 + v15_5_5 <= 1
 rest20_PassageiroEhEmbarcadoApenasNaOrigem1: v1_1_1 + v1_2_1 + v1_3_1
   + v1_4_1 + v1_5_1 = 0
 rest20_PassageiroEhEmbarcadoApenasNaOrigem2: v2_1_1 + v2_2_1 + v2_3_1
   + v2_4_1 + v2_5_1 = 0
 rest20_PassageiroEhEmbarcadoApenasNaOrigem3: v3_1_1 + v3_2_1 + v3_3_1
   + v3_4_1 + v3_5_1 = 0
 rest20_PassageiroEhEmbarcadoApenasNaOrigem4: v4_1_2 + v4_2_2 + v4_3_2
   + v4_4_2 + v4_5_2 = 0
 rest20_PassageiroEhEmbarcadoApenasNaOrigem5: v5_1_2 + v5_2_2 + v5_3_2
   + v5_4_2 + v5_5_2 = 0
 rest20_PassageiroEhEmbarcadoApenasNaOrigem6: v6_1_2 + v6_2_2 + v6_3_2
   + v6_4_2 + v6_5_2 = 0
 rest20_PassageiroEhEmbarcadoApenasNaOrigem7: v7_1_3 + v7_2_3 + v7_3_3
   + v7_4_3 + v7_5_3 = 0
 rest20_PassageiroEhEmbarcadoApenasNaOrigem8: v8_1_3 + v8_2_3 + v8_3_3
   + v8_4_3 + v8_5_3 = 0
 rest20_PassageiroEhEmbarcadoApenasNaOrigem9: v9_1_3 + v9_2_3 + v9_3_3
   + v9_4_3 + v9_5_3 = 0
 rest20_PassageiroEhEmbarcadoApenasNaOrigem10: v10_1_4 + v10_2_4 + v10_3_4
   + v10_4_4 + v10_5_4 = 0
 rest20_PassageiroEhEmbarcadoApenasNaOrigem11: v11_1_4 + v11_2_4 + v11_3_4
   + v11_4_4 + v11_5_4 = 0
 rest20_PassageiroEhEmbarcadoApenasNaOrigem12: v12_1_4 + v12_2_4 + v12_3_4
   + v12_4_4 + v12_5_4 = 0
 rest20_PassageiroEhEmbarcadoApenasNaOrigem13: v13_1_5 + v13_2_5 + v13_3_5
   + v13_4_5 + v13_5_5 = 0
 rest20_PassageiroEhEmbarcadoApenasNaOrigem14: v14_1_5 + v14_2_5 + v14_3_5
   + v14_4_5 + v14_5_5 = 0
 rest20_PassageiroEhEmbarcadoApenasNaOrigem15: v15_1_5 + v15_2_5 + v15_3_5
   + v15_4_5 + v15_5_5 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f1_1 + v1_2_1 + v1_3_1
   + v1_4_1 + v1_5_1 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f2_1 + v2_2_1 + v2_3_1
   + v2_4_1 + v2_5_1 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f3_1 + v3_2_1 + v3_3_1
   + v3_4_1 + v3_5_1 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f4_1 + v4_2_1 + v4_3_1
   + v4_4_1 + v4_5_1 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f5_1 + v5_2_1 + v5_3_1
   + v5_4_1 + v5_5_1 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f6_1 + v6_2_1 + v6_3_1
   + v6_4_1 + v6_5_1 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f7_1 + v7_2_1 + v7_3_1
   + v7_4_1 + v7_5_1 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f8_1 + v8_2_1 + v8_3_1
   + v8_4_1 + v8_5_1 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f9_1 + v9_2_1 + v9_3_1
   + v9_4_1 + v9_5_1 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f10_1 + v10_2_1
   + v10_3_1 + v10_4_1 + v10_5_1 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f11_1 + v11_2_1
   + v11_3_1 + v11_4_1 + v11_5_1 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f12_1 + v12_2_1
   + v12_3_1 + v12_4_1 + v12_5_1 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f13_1 + v13_2_1
   + v13_3_1 + v13_4_1 + v13_5_1 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f14_1 + v14_2_1
   + v14_3_1 + v14_4_1 + v14_5_1 = 0
 rest21_obrigaQuemEstiverChegandoEm1Desembarcar: - f15_1 + v15_2_1
   + v15_3_1 + v15_4_1 + v15_5_1 = 0
 rest8_bonusMinimo: [ 469 x2_1 * p2 + 469 x2_2 * p2 + 469 x2_3 * p2
   + 469 x2_4 * p2 + 469 x2_5 * p2 + 499 x3_1 * p3 + 499 x3_2 * p3
   + 499 x3_3 * p3 + 499 x3_4 * p3 + 499 x3_5 * p3 + 563 x4_1 * p4
   + 563 x4_2 * p4 + 563 x4_3 * p4 + 563 x4_4 * p4 + 563 x4_5 * p4
   + 471 x5_1 * p5 + 471 x5_2 * p5 + 471 x5_3 * p5 + 471 x5_4 * p5
   + 471 x5_5 * p5 ] >= 1001
 rest9_tempoLimitePassageiro1: 60 v1_1_2 + 99 v1_1_3 + 82 v1_1_4
   + 22 v1_1_5 + 28 v1_2_1 + 88 v1_2_3 + 36 v1_2_4 + 62 v1_2_5 + 99 v1_3_1
   + 48 v1_3_2 + 76 v1_3_4 + 37 v1_3_5 + 28 v1_4_1 + 42 v1_4_2 + 76 v1_4_3
   + 45 v1_4_5 + 56 v1_5_1 + 62 v1_5_2 + 53 v1_5_3 + 37 v1_5_4 + [
   43 p2 * v1_2_1 + 43 p2 * v1_2_2 + 43 p2 * v1_2_3 + 43 p2 * v1_2_4
   + 43 p2 * v1_2_5 + 40 p3 * v1_3_1 + 40 p3 * v1_3_2 + 40 p3 * v1_3_3
   + 40 p3 * v1_3_4 + 40 p3 * v1_3_5 + 33 p4 * v1_4_1 + 33 p4 * v1_4_2
   + 33 p4 * v1_4_3 + 33 p4 * v1_4_4 + 33 p4 * v1_4_5 + 46 p5 * v1_5_1
   + 46 p5 * v1_5_2 + 46 p5 * v1_5_3 + 46 p5 * v1_5_4 + 46 p5 * v1_5_5 ]
   <= 177
 rest9_tempoLimitePassageiro2: 60 v2_1_2 + 99 v2_1_3 + 82 v2_1_4
   + 22 v2_1_5 + 28 v2_2_1 + 88 v2_2_3 + 36 v2_2_4 + 62 v2_2_5 + 99 v2_3_1
   + 48 v2_3_2 + 76 v2_3_4 + 37 v2_3_5 + 28 v2_4_1 + 42 v2_4_2 + 76 v2_4_3
   + 45 v2_4_5 + 56 v2_5_1 + 62 v2_5_2 + 53 v2_5_3 + 37 v2_5_4 + [
   43 p2 * v2_2_1 + 43 p2 * v2_2_2 + 43 p2 * v2_2_3 + 43 p2 * v2_2_4
   + 43 p2 * v2_2_5 + 40 p3 * v2_3_1 + 40 p3 * v2_3_2 + 40 p3 * v2_3_3
   + 40 p3 * v2_3_4 + 40 p3 * v2_3_5 + 33 p4 * v2_4_1 + 33 p4 * v2_4_2
   + 33 p4 * v2_4_3 + 33 p4 * v2_4_4 + 33 p4 * v2_4_5 + 46 p5 * v2_5_1
   + 46 p5 * v2_5_2 + 46 p5 * v2_5_3 + 46 p5 * v2_5_4 + 46 p5 * v2_5_5 ]
   <= 66
 rest9_tempoLimitePassageiro3: 60 v3_1_2 + 99 v3_1_3 + 82 v3_1_4
   + 22 v3_1_5 + 28 v3_2_1 + 88 v3_2_3 + 36 v3_2_4 + 62 v3_2_5 + 99 v3_3_1
   + 48 v3_3_2 + 76 v3_3_4 + 37 v3_3_5 + 28 v3_4_1 + 42 v3_4_2 + 76 v3_4_3
   + 45 v3_4_5 + 56 v3_5_1 + 62 v3_5_2 + 53 v3_5_3 + 37 v3_5_4 + [
   43 p2 * v3_2_1 + 43 p2 * v3_2_2 + 43 p2 * v3_2_3 + 43 p2 * v3_2_4
   + 43 p2 * v3_2_5 + 40 p3 * v3_3_1 + 40 p3 * v3_3_2 + 40 p3 * v3_3_3
   + 40 p3 * v3_3_4 + 40 p3 * v3_3_5 + 33 p4 * v3_4_1 + 33 p4 * v3_4_2
   + 33 p4 * v3_4_3 + 33 p4 * v3_4_4 + 33 p4 * v3_4_5 + 46 p5 * v3_5_1
   + 46 p5 * v3_5_2 + 46 p5 * v3_5_3 + 46 p5 * v3_5_4 + 46 p5 * v3_5_5 ]
   <= 66
 rest9_tempoLimitePassageiro4: 60 v4_1_2 + 99 v4_1_3 + 82 v4_1_4
   + 22 v4_1_5 + 28 v4_2_1 + 88 v4_2_3 + 36 v4_2_4 + 62 v4_2_5 + 99 v4_3_1
   + 48 v4_3_2 + 76 v4_3_4 + 37 v4_3_5 + 28 v4_4_1 + 42 v4_4_2 + 76 v4_4_3
   + 45 v4_4_5 + 56 v4_5_1 + 62 v4_5_2 + 53 v4_5_3 + 37 v4_5_4 + [
   43 p2 * v4_2_1 + 43 p2 * v4_2_2 + 43 p2 * v4_2_3 + 43 p2 * v4_2_4
   + 43 p2 * v4_2_5 + 40 p3 * v4_3_1 + 40 p3 * v4_3_2 + 40 p3 * v4_3_3
   + 40 p3 * v4_3_4 + 40 p3 * v4_3_5 + 33 p4 * v4_4_1 + 33 p4 * v4_4_2
   + 33 p4 * v4_4_3 + 33 p4 * v4_4_4 + 33 p4 * v4_4_5 + 46 p5 * v4_5_1
   + 46 p5 * v4_5_2 + 46 p5 * v4_5_3 + 46 p5 * v4_5_4 + 46 p5 * v4_5_5 ]
   <= 264
 rest9_tempoLimitePassageiro5: 60 v5_1_2 + 99 v5_1_3 + 82 v5_1_4
   + 22 v5_1_5 + 28 v5_2_1 + 88 v5_2_3 + 36 v5_2_4 + 62 v5_2_5 + 99 v5_3_1
   + 48 v5_3_2 + 76 v5_3_4 + 37 v5_3_5 + 28 v5_4_1 + 42 v5_4_2 + 76 v5_4_3
   + 45 v5_4_5 + 56 v5_5_1 + 62 v5_5_2 + 53 v5_5_3 + 37 v5_5_4 + [
   43 p2 * v5_2_1 + 43 p2 * v5_2_2 + 43 p2 * v5_2_3 + 43 p2 * v5_2_4
   + 43 p2 * v5_2_5 + 40 p3 * v5_3_1 + 40 p3 * v5_3_2 + 40 p3 * v5_3_3
   + 40 p3 * v5_3_4 + 40 p3 * v5_3_5 + 33 p4 * v5_4_1 + 33 p4 * v5_4_2
   + 33 p4 * v5_4_3 + 33 p4 * v5_4_4 + 33 p4 * v5_4_5 + 46 p5 * v5_5_1
   + 46 p5 * v5_5_2 + 46 p5 * v5_5_3 + 46 p5 * v5_5_4 + 46 p5 * v5_5_5 ]
   <= 264
 rest9_tempoLimitePassageiro6: 60 v6_1_2 + 99 v6_1_3 + 82 v6_1_4
   + 22 v6_1_5 + 28 v6_2_1 + 88 v6_2_3 + 36 v6_2_4 + 62 v6_2_5 + 99 v6_3_1
   + 48 v6_3_2 + 76 v6_3_4 + 37 v6_3_5 + 28 v6_4_1 + 42 v6_4_2 + 76 v6_4_3
   + 45 v6_4_5 + 56 v6_5_1 + 62 v6_5_2 + 53 v6_5_3 + 37 v6_5_4 + [
   43 p2 * v6_2_1 + 43 p2 * v6_2_2 + 43 p2 * v6_2_3 + 43 p2 * v6_2_4
   + 43 p2 * v6_2_5 + 40 p3 * v6_3_1 + 40 p3 * v6_3_2 + 40 p3 * v6_3_3
   + 40 p3 * v6_3_4 + 40 p3 * v6_3_5 + 33 p4 * v6_4_1 + 33 p4 * v6_4_2
   + 33 p4 * v6_4_3 + 33 p4 * v6_4_4 + 33 p4 * v6_4_5 + 46 p5 * v6_5_1
   + 46 p5 * v6_5_2 + 46 p5 * v6_5_3 + 46 p5 * v6_5_4 + 46 p5 * v6_5_5 ]
   <= 264
 rest9_tempoLimitePassageiro7: 60 v7_1_2 + 99 v7_1_3 + 82 v7_1_4
   + 22 v7_1_5 + 28 v7_2_1 + 88 v7_2_3 + 36 v7_2_4 + 62 v7_2_5 + 99 v7_3_1
   + 48 v7_3_2 + 76 v7_3_4 + 37 v7_3_5 + 28 v7_4_1 + 42 v7_4_2 + 76 v7_4_3
   + 45 v7_4_5 + 56 v7_5_1 + 62 v7_5_2 + 53 v7_5_3 + 37 v7_5_4 + [
   43 p2 * v7_2_1 + 43 p2 * v7_2_2 + 43 p2 * v7_2_3 + 43 p2 * v7_2_4
   + 43 p2 * v7_2_5 + 40 p3 * v7_3_1 + 40 p3 * v7_3_2 + 40 p3 * v7_3_3
   + 40 p3 * v7_3_4 + 40 p3 * v7_3_5 + 33 p4 * v7_4_1 + 33 p4 * v7_4_2
   + 33 p4 * v7_4_3 + 33 p4 * v7_4_4 + 33 p4 * v7_4_5 + 46 p5 * v7_5_1
   + 46 p5 * v7_5_2 + 46 p5 * v7_5_3 + 46 p5 * v7_5_4 + 46 p5 * v7_5_5 ]
   <= 228
 rest9_tempoLimitePassageiro8: 60 v8_1_2 + 99 v8_1_3 + 82 v8_1_4
   + 22 v8_1_5 + 28 v8_2_1 + 88 v8_2_3 + 36 v8_2_4 + 62 v8_2_5 + 99 v8_3_1
   + 48 v8_3_2 + 76 v8_3_4 + 37 v8_3_5 + 28 v8_4_1 + 42 v8_4_2 + 76 v8_4_3
   + 45 v8_4_5 + 56 v8_5_1 + 62 v8_5_2 + 53 v8_5_3 + 37 v8_5_4 + [
   43 p2 * v8_2_1 + 43 p2 * v8_2_2 + 43 p2 * v8_2_3 + 43 p2 * v8_2_4
   + 43 p2 * v8_2_5 + 40 p3 * v8_3_1 + 40 p3 * v8_3_2 + 40 p3 * v8_3_3
   + 40 p3 * v8_3_4 + 40 p3 * v8_3_5 + 33 p4 * v8_4_1 + 33 p4 * v8_4_2
   + 33 p4 * v8_4_3 + 33 p4 * v8_4_4 + 33 p4 * v8_4_5 + 46 p5 * v8_5_1
   + 46 p5 * v8_5_2 + 46 p5 * v8_5_3 + 46 p5 * v8_5_4 + 46 p5 * v8_5_5 ]
   <= 144
 rest9_tempoLimitePassageiro9: 60 v9_1_2 + 99 v9_1_3 + 82 v9_1_4
   + 22 v9_1_5 + 28 v9_2_1 + 88 v9_2_3 + 36 v9_2_4 + 62 v9_2_5 + 99 v9_3_1
   + 48 v9_3_2 + 76 v9_3_4 + 37 v9_3_5 + 28 v9_4_1 + 42 v9_4_2 + 76 v9_4_3
   + 45 v9_4_5 + 56 v9_5_1 + 62 v9_5_2 + 53 v9_5_3 + 37 v9_5_4 + [
   43 p2 * v9_2_1 + 43 p2 * v9_2_2 + 43 p2 * v9_2_3 + 43 p2 * v9_2_4
   + 43 p2 * v9_2_5 + 40 p3 * v9_3_1 + 40 p3 * v9_3_2 + 40 p3 * v9_3_3
   + 40 p3 * v9_3_4 + 40 p3 * v9_3_5 + 33 p4 * v9_4_1 + 33 p4 * v9_4_2
   + 33 p4 * v9_4_3 + 33 p4 * v9_4_4 + 33 p4 * v9_4_5 + 46 p5 * v9_5_1
   + 46 p5 * v9_5_2 + 46 p5 * v9_5_3 + 46 p5 * v9_5_4 + 46 p5 * v9_5_5 ]
   <= 228
 rest9_tempoLimitePassageiro10: 60 v10_1_2 + 99 v10_1_3 + 82 v10_1_4
   + 22 v10_1_5 + 28 v10_2_1 + 88 v10_2_3 + 36 v10_2_4 + 62 v10_2_5
   + 99 v10_3_1 + 48 v10_3_2 + 76 v10_3_4 + 37 v10_3_5 + 28 v10_4_1
   + 42 v10_4_2 + 76 v10_4_3 + 45 v10_4_5 + 56 v10_5_1 + 62 v10_5_2
   + 53 v10_5_3 + 37 v10_5_4 + [ 43 p2 * v10_2_1 + 43 p2 * v10_2_2
   + 43 p2 * v10_2_3 + 43 p2 * v10_2_4 + 43 p2 * v10_2_5 + 40 p3 * v10_3_1
   + 40 p3 * v10_3_2 + 40 p3 * v10_3_3 + 40 p3 * v10_3_4 + 40 p3 * v10_3_5
   + 33 p4 * v10_4_1 + 33 p4 * v10_4_2 + 33 p4 * v10_4_3 + 33 p4 * v10_4_4
   + 33 p4 * v10_4_5 + 46 p5 * v10_5_1 + 46 p5 * v10_5_2 + 46 p5 * v10_5_3
   + 46 p5 * v10_5_4 + 46 p5 * v10_5_5 ] <= 135
 rest9_tempoLimitePassageiro11: 60 v11_1_2 + 99 v11_1_3 + 82 v11_1_4
   + 22 v11_1_5 + 28 v11_2_1 + 88 v11_2_3 + 36 v11_2_4 + 62 v11_2_5
   + 99 v11_3_1 + 48 v11_3_2 + 76 v11_3_4 + 37 v11_3_5 + 28 v11_4_1
   + 42 v11_4_2 + 76 v11_4_3 + 45 v11_4_5 + 56 v11_5_1 + 62 v11_5_2
   + 53 v11_5_3 + 37 v11_5_4 + [ 43 p2 * v11_2_1 + 43 p2 * v11_2_2
   + 43 p2 * v11_2_3 + 43 p2 * v11_2_4 + 43 p2 * v11_2_5 + 40 p3 * v11_3_1
   + 40 p3 * v11_3_2 + 40 p3 * v11_3_3 + 40 p3 * v11_3_4 + 40 p3 * v11_3_5
   + 33 p4 * v11_4_1 + 33 p4 * v11_4_2 + 33 p4 * v11_4_3 + 33 p4 * v11_4_4
   + 33 p4 * v11_4_5 + 46 p5 * v11_5_1 + 46 p5 * v11_5_2 + 46 p5 * v11_5_3
   + 46 p5 * v11_5_4 + 46 p5 * v11_5_5 ] <= 228
 rest9_tempoLimitePassageiro12: 60 v12_1_2 + 99 v12_1_3 + 82 v12_1_4
   + 22 v12_1_5 + 28 v12_2_1 + 88 v12_2_3 + 36 v12_2_4 + 62 v12_2_5
   + 99 v12_3_1 + 48 v12_3_2 + 76 v12_3_4 + 37 v12_3_5 + 28 v12_4_1
   + 42 v12_4_2 + 76 v12_4_3 + 45 v12_4_5 + 56 v12_5_1 + 62 v12_5_2
   + 53 v12_5_3 + 37 v12_5_4 + [ 43 p2 * v12_2_1 + 43 p2 * v12_2_2
   + 43 p2 * v12_2_3 + 43 p2 * v12_2_4 + 43 p2 * v12_2_5 + 40 p3 * v12_3_1
   + 40 p3 * v12_3_2 + 40 p3 * v12_3_3 + 40 p3 * v12_3_4 + 40 p3 * v12_3_5
   + 33 p4 * v12_4_1 + 33 p4 * v12_4_2 + 33 p4 * v12_4_3 + 33 p4 * v12_4_4
   + 33 p4 * v12_4_5 + 46 p5 * v12_5_1 + 46 p5 * v12_5_2 + 46 p5 * v12_5_3
   + 46 p5 * v12_5_4 + 46 p5 * v12_5_5 ] <= 126
 rest9_tempoLimitePassageiro13: 60 v13_1_2 + 99 v13_1_3 + 82 v13_1_4
   + 22 v13_1_5 + 28 v13_2_1 + 88 v13_2_3 + 36 v13_2_4 + 62 v13_2_5
   + 99 v13_3_1 + 48 v13_3_2 + 76 v13_3_4 + 37 v13_3_5 + 28 v13_4_1
   + 42 v13_4_2 + 76 v13_4_3 + 45 v13_4_5 + 56 v13_5_1 + 62 v13_5_2
   + 53 v13_5_3 + 37 v13_5_4 + [ 43 p2 * v13_2_1 + 43 p2 * v13_2_2
   + 43 p2 * v13_2_3 + 43 p2 * v13_2_4 + 43 p2 * v13_2_5 + 40 p3 * v13_3_1
   + 40 p3 * v13_3_2 + 40 p3 * v13_3_3 + 40 p3 * v13_3_4 + 40 p3 * v13_3_5
   + 33 p4 * v13_4_1 + 33 p4 * v13_4_2 + 33 p4 * v13_4_3 + 33 p4 * v13_4_4
   + 33 p4 * v13_4_5 + 46 p5 * v13_5_1 + 46 p5 * v13_5_2 + 46 p5 * v13_5_3
   + 46 p5 * v13_5_4 + 46 p5 * v13_5_5 ] <= 186
 rest9_tempoLimitePassageiro14: 60 v14_1_2 + 99 v14_1_3 + 82 v14_1_4
   + 22 v14_1_5 + 28 v14_2_1 + 88 v14_2_3 + 36 v14_2_4 + 62 v14_2_5
   + 99 v14_3_1 + 48 v14_3_2 + 76 v14_3_4 + 37 v14_3_5 + 28 v14_4_1
   + 42 v14_4_2 + 76 v14_4_3 + 45 v14_4_5 + 56 v14_5_1 + 62 v14_5_2
   + 53 v14_5_3 + 37 v14_5_4 + [ 43 p2 * v14_2_1 + 43 p2 * v14_2_2
   + 43 p2 * v14_2_3 + 43 p2 * v14_2_4 + 43 p2 * v14_2_5 + 40 p3 * v14_3_1
   + 40 p3 * v14_3_2 + 40 p3 * v14_3_3 + 40 p3 * v14_3_4 + 40 p3 * v14_3_5
   + 33 p4 * v14_4_1 + 33 p4 * v14_4_2 + 33 p4 * v14_4_3 + 33 p4 * v14_4_4
   + 33 p4 * v14_4_5 + 46 p5 * v14_5_1 + 46 p5 * v14_5_2 + 46 p5 * v14_5_3
   + 46 p5 * v14_5_4 + 46 p5 * v14_5_5 ] <= 159
 rest9_tempoLimitePassageiro15: 60 v15_1_2 + 99 v15_1_3 + 82 v15_1_4
   + 22 v15_1_5 + 28 v15_2_1 + 88 v15_2_3 + 36 v15_2_4 + 62 v15_2_5
   + 99 v15_3_1 + 48 v15_3_2 + 76 v15_3_4 + 37 v15_3_5 + 28 v15_4_1
   + 42 v15_4_2 + 76 v15_4_3 + 45 v15_4_5 + 56 v15_5_1 + 62 v15_5_2
   + 53 v15_5_3 + 37 v15_5_4 + [ 43 p2 * v15_2_1 + 43 p2 * v15_2_2
   + 43 p2 * v15_2_3 + 43 p2 * v15_2_4 + 43 p2 * v15_2_5 + 40 p3 * v15_3_1
   + 40 p3 * v15_3_2 + 40 p3 * v15_3_3 + 40 p3 * v15_3_4 + 40 p3 * v15_3_5
   + 33 p4 * v15_4_1 + 33 p4 * v15_4_2 + 33 p4 * v15_4_3 + 33 p4 * v15_4_4
   + 33 p4 * v15_4_5 + 46 p5 * v15_5_1 + 46 p5 * v15_5_2 + 46 p5 * v15_5_3
   + 46 p5 * v15_5_4 + 46 p5 * v15_5_5 ] <= 159
 rest12_tarifaMaxPassageiro1: [ 232 taxaRateio1_2 * v1_1_2
   + 665 taxaRateio1_3 * v1_1_3 + 269 taxaRateio1_4 * v1_1_4
   + 376 taxaRateio1_5 * v1_1_5 + 498 taxaRateio2_1 * v1_2_1
   + 270 taxaRateio2_3 * v1_2_3 + 476 taxaRateio2_4 * v1_2_4
   + 296 taxaRateio2_5 * v1_2_5 + 251 taxaRateio3_1 * v1_3_1
   + 440 taxaRateio3_2 * v1_3_2 + 368 taxaRateio3_4 * v1_3_4
   + 434 taxaRateio3_5 * v1_3_5 + 626 taxaRateio4_1 * v1_4_1
   + 425 taxaRateio4_2 * v1_4_2 + 268 taxaRateio4_3 * v1_4_3
   + 630 taxaRateio4_5 * v1_4_5 + 420 taxaRateio5_1 * v1_5_1
   + 250 taxaRateio5_2 * v1_5_2 + 521 taxaRateio5_3 * v1_5_3
   + 520 taxaRateio5_4 * v1_5_4 ] <= 112
 rest12_tarifaMaxPassageiro2: [ 232 taxaRateio1_2 * v2_1_2
   + 665 taxaRateio1_3 * v2_1_3 + 269 taxaRateio1_4 * v2_1_4
   + 376 taxaRateio1_5 * v2_1_5 + 498 taxaRateio2_1 * v2_2_1
   + 270 taxaRateio2_3 * v2_2_3 + 476 taxaRateio2_4 * v2_2_4
   + 296 taxaRateio2_5 * v2_2_5 + 251 taxaRateio3_1 * v2_3_1
   + 440 taxaRateio3_2 * v2_3_2 + 368 taxaRateio3_4 * v2_3_4
   + 434 taxaRateio3_5 * v2_3_5 + 626 taxaRateio4_1 * v2_4_1
   + 425 taxaRateio4_2 * v2_4_2 + 268 taxaRateio4_3 * v2_4_3
   + 630 taxaRateio4_5 * v2_4_5 + 420 taxaRateio5_1 * v2_5_1
   + 250 taxaRateio5_2 * v2_5_2 + 521 taxaRateio5_3 * v2_5_3
   + 520 taxaRateio5_4 * v2_5_4 ] <= 128
 rest12_tarifaMaxPassageiro3: [ 232 taxaRateio1_2 * v3_1_2
   + 665 taxaRateio1_3 * v3_1_3 + 269 taxaRateio1_4 * v3_1_4
   + 376 taxaRateio1_5 * v3_1_5 + 498 taxaRateio2_1 * v3_2_1
   + 270 taxaRateio2_3 * v3_2_3 + 476 taxaRateio2_4 * v3_2_4
   + 296 taxaRateio2_5 * v3_2_5 + 251 taxaRateio3_1 * v3_3_1
   + 440 taxaRateio3_2 * v3_3_2 + 368 taxaRateio3_4 * v3_3_4
   + 434 taxaRateio3_5 * v3_3_5 + 626 taxaRateio4_1 * v3_4_1
   + 425 taxaRateio4_2 * v3_4_2 + 268 taxaRateio4_3 * v3_4_3
   + 630 taxaRateio4_5 * v3_4_5 + 420 taxaRateio5_1 * v3_5_1
   + 250 taxaRateio5_2 * v3_5_2 + 521 taxaRateio5_3 * v3_5_3
   + 520 taxaRateio5_4 * v3_5_4 ] <= 144
 rest12_tarifaMaxPassageiro4: [ 232 taxaRateio1_2 * v4_1_2
   + 665 taxaRateio1_3 * v4_1_3 + 269 taxaRateio1_4 * v4_1_4
   + 376 taxaRateio1_5 * v4_1_5 + 498 taxaRateio2_1 * v4_2_1
   + 270 taxaRateio2_3 * v4_2_3 + 476 taxaRateio2_4 * v4_2_4
   + 296 taxaRateio2_5 * v4_2_5 + 251 taxaRateio3_1 * v4_3_1
   + 440 taxaRateio3_2 * v4_3_2 + 368 taxaRateio3_4 * v4_3_4
   + 434 taxaRateio3_5 * v4_3_5 + 626 taxaRateio4_1 * v4_4_1
   + 425 taxaRateio4_2 * v4_4_2 + 268 taxaRateio4_3 * v4_4_3
   + 630 taxaRateio4_5 * v4_4_5 + 420 taxaRateio5_1 * v4_5_1
   + 250 taxaRateio5_2 * v4_5_2 + 521 taxaRateio5_3 * v4_5_3
   + 520 taxaRateio5_4 * v4_5_4 ] <= 144
 rest12_tarifaMaxPassageiro5: [ 232 taxaRateio1_2 * v5_1_2
   + 665 taxaRateio1_3 * v5_1_3 + 269 taxaRateio1_4 * v5_1_4
   + 376 taxaRateio1_5 * v5_1_5 + 498 taxaRateio2_1 * v5_2_1
   + 270 taxaRateio2_3 * v5_2_3 + 476 taxaRateio2_4 * v5_2_4
   + 296 taxaRateio2_5 * v5_2_5 + 251 taxaRateio3_1 * v5_3_1
   + 440 taxaRateio3_2 * v5_3_2 + 368 taxaRateio3_4 * v5_3_4
   + 434 taxaRateio3_5 * v5_3_5 + 626 taxaRateio4_1 * v5_4_1
   + 425 taxaRateio4_2 * v5_4_2 + 268 taxaRateio4_3 * v5_4_3
   + 630 taxaRateio4_5 * v5_4_5 + 420 taxaRateio5_1 * v5_5_1
   + 250 taxaRateio5_2 * v5_5_2 + 521 taxaRateio5_3 * v5_5_3
   + 520 taxaRateio5_4 * v5_5_4 ] <= 144
 rest12_tarifaMaxPassageiro6: [ 232 taxaRateio1_2 * v6_1_2
   + 665 taxaRateio1_3 * v6_1_3 + 269 taxaRateio1_4 * v6_1_4
   + 376 taxaRateio1_5 * v6_1_5 + 498 taxaRateio2_1 * v6_2_1
   + 270 taxaRateio2_3 * v6_2_3 + 476 taxaRateio2_4 * v6_2_4
   + 296 taxaRateio2_5 * v6_2_5 + 251 taxaRateio3_1 * v6_3_1
   + 440 taxaRateio3_2 * v6_3_2 + 368 taxaRateio3_4 * v6_3_4
   + 434 taxaRateio3_5 * v6_3_5 + 626 taxaRateio4_1 * v6_4_1
   + 425 taxaRateio4_2 * v6_4_2 + 268 taxaRateio4_3 * v6_4_3
   + 630 taxaRateio4_5 * v6_4_5 + 420 taxaRateio5_1 * v6_5_1
   + 250 taxaRateio5_2 * v6_5_2 + 521 taxaRateio5_3 * v6_5_3
   + 520 taxaRateio5_4 * v6_5_4 ] <= 128
 rest12_tarifaMaxPassageiro7: [ 232 taxaRateio1_2 * v7_1_2
   + 665 taxaRateio1_3 * v7_1_3 + 269 taxaRateio1_4 * v7_1_4
   + 376 taxaRateio1_5 * v7_1_5 + 498 taxaRateio2_1 * v7_2_1
   + 270 taxaRateio2_3 * v7_2_3 + 476 taxaRateio2_4 * v7_2_4
   + 296 taxaRateio2_5 * v7_2_5 + 251 taxaRateio3_1 * v7_3_1
   + 440 taxaRateio3_2 * v7_3_2 + 368 taxaRateio3_4 * v7_3_4
   + 434 taxaRateio3_5 * v7_3_5 + 626 taxaRateio4_1 * v7_4_1
   + 425 taxaRateio4_2 * v7_4_2 + 268 taxaRateio4_3 * v7_4_3
   + 630 taxaRateio4_5 * v7_4_5 + 420 taxaRateio5_1 * v7_5_1
   + 250 taxaRateio5_2 * v7_5_2 + 521 taxaRateio5_3 * v7_5_3
   + 520 taxaRateio5_4 * v7_5_4 ] <= 96
 rest12_tarifaMaxPassageiro8: [ 232 taxaRateio1_2 * v8_1_2
   + 665 taxaRateio1_3 * v8_1_3 + 269 taxaRateio1_4 * v8_1_4
   + 376 taxaRateio1_5 * v8_1_5 + 498 taxaRateio2_1 * v8_2_1
   + 270 taxaRateio2_3 * v8_2_3 + 476 taxaRateio2_4 * v8_2_4
   + 296 taxaRateio2_5 * v8_2_5 + 251 taxaRateio3_1 * v8_3_1
   + 440 taxaRateio3_2 * v8_3_2 + 368 taxaRateio3_4 * v8_3_4
   + 434 taxaRateio3_5 * v8_3_5 + 626 taxaRateio4_1 * v8_4_1
   + 425 taxaRateio4_2 * v8_4_2 + 268 taxaRateio4_3 * v8_4_3
   + 630 taxaRateio4_5 * v8_4_5 + 420 taxaRateio5_1 * v8_5_1
   + 250 taxaRateio5_2 * v8_5_2 + 521 taxaRateio5_3 * v8_5_3
   + 520 taxaRateio5_4 * v8_5_4 ] <= 96
 rest12_tarifaMaxPassageiro9: [ 232 taxaRateio1_2 * v9_1_2
   + 665 taxaRateio1_3 * v9_1_3 + 269 taxaRateio1_4 * v9_1_4
   + 376 taxaRateio1_5 * v9_1_5 + 498 taxaRateio2_1 * v9_2_1
   + 270 taxaRateio2_3 * v9_2_3 + 476 taxaRateio2_4 * v9_2_4
   + 296 taxaRateio2_5 * v9_2_5 + 251 taxaRateio3_1 * v9_3_1
   + 440 taxaRateio3_2 * v9_3_2 + 368 taxaRateio3_4 * v9_3_4
   + 434 taxaRateio3_5 * v9_3_5 + 626 taxaRateio4_1 * v9_4_1
   + 425 taxaRateio4_2 * v9_4_2 + 268 taxaRateio4_3 * v9_4_3
   + 630 taxaRateio4_5 * v9_4_5 + 420 taxaRateio5_1 * v9_5_1
   + 250 taxaRateio5_2 * v9_5_2 + 521 taxaRateio5_3 * v9_5_3
   + 520 taxaRateio5_4 * v9_5_4 ] <= 128
 rest12_tarifaMaxPassageiro10: [ 232 taxaRateio1_2 * v10_1_2
   + 665 taxaRateio1_3 * v10_1_3 + 269 taxaRateio1_4 * v10_1_4
   + 376 taxaRateio1_5 * v10_1_5 + 498 taxaRateio2_1 * v10_2_1
   + 270 taxaRateio2_3 * v10_2_3 + 476 taxaRateio2_4 * v10_2_4
   + 296 taxaRateio2_5 * v10_2_5 + 251 taxaRateio3_1 * v10_3_1
   + 440 taxaRateio3_2 * v10_3_2 + 368 taxaRateio3_4 * v10_3_4
   + 434 taxaRateio3_5 * v10_3_5 + 626 taxaRateio4_1 * v10_4_1
   + 425 taxaRateio4_2 * v10_4_2 + 268 taxaRateio4_3 * v10_4_3
   + 630 taxaRateio4_5 * v10_4_5 + 420 taxaRateio5_1 * v10_5_1
   + 250 taxaRateio5_2 * v10_5_2 + 521 taxaRateio5_3 * v10_5_3
   + 520 taxaRateio5_4 * v10_5_4 ] <= 128
 rest12_tarifaMaxPassageiro11: [ 232 taxaRateio1_2 * v11_1_2
   + 665 taxaRateio1_3 * v11_1_3 + 269 taxaRateio1_4 * v11_1_4
   + 376 taxaRateio1_5 * v11_1_5 + 498 taxaRateio2_1 * v11_2_1
   + 270 taxaRateio2_3 * v11_2_3 + 476 taxaRateio2_4 * v11_2_4
   + 296 taxaRateio2_5 * v11_2_5 + 251 taxaRateio3_1 * v11_3_1
   + 440 taxaRateio3_2 * v11_3_2 + 368 taxaRateio3_4 * v11_3_4
   + 434 taxaRateio3_5 * v11_3_5 + 626 taxaRateio4_1 * v11_4_1
   + 425 taxaRateio4_2 * v11_4_2 + 268 taxaRateio4_3 * v11_4_3
   + 630 taxaRateio4_5 * v11_4_5 + 420 taxaRateio5_1 * v11_5_1
   + 250 taxaRateio5_2 * v11_5_2 + 521 taxaRateio5_3 * v11_5_3
   + 520 taxaRateio5_4 * v11_5_4 ] <= 128
 rest12_tarifaMaxPassageiro12: [ 232 taxaRateio1_2 * v12_1_2
   + 665 taxaRateio1_3 * v12_1_3 + 269 taxaRateio1_4 * v12_1_4
   + 376 taxaRateio1_5 * v12_1_5 + 498 taxaRateio2_1 * v12_2_1
   + 270 taxaRateio2_3 * v12_2_3 + 476 taxaRateio2_4 * v12_2_4
   + 296 taxaRateio2_5 * v12_2_5 + 251 taxaRateio3_1 * v12_3_1
   + 440 taxaRateio3_2 * v12_3_2 + 368 taxaRateio3_4 * v12_3_4
   + 434 taxaRateio3_5 * v12_3_5 + 626 taxaRateio4_1 * v12_4_1
   + 425 taxaRateio4_2 * v12_4_2 + 268 taxaRateio4_3 * v12_4_3
   + 630 taxaRateio4_5 * v12_4_5 + 420 taxaRateio5_1 * v12_5_1
   + 250 taxaRateio5_2 * v12_5_2 + 521 taxaRateio5_3 * v12_5_3
   + 520 taxaRateio5_4 * v12_5_4 ] <= 112
 rest12_tarifaMaxPassageiro13: [ 232 taxaRateio1_2 * v13_1_2
   + 665 taxaRateio1_3 * v13_1_3 + 269 taxaRateio1_4 * v13_1_4
   + 376 taxaRateio1_5 * v13_1_5 + 498 taxaRateio2_1 * v13_2_1
   + 270 taxaRateio2_3 * v13_2_3 + 476 taxaRateio2_4 * v13_2_4
   + 296 taxaRateio2_5 * v13_2_5 + 251 taxaRateio3_1 * v13_3_1
   + 440 taxaRateio3_2 * v13_3_2 + 368 taxaRateio3_4 * v13_3_4
   + 434 taxaRateio3_5 * v13_3_5 + 626 taxaRateio4_1 * v13_4_1
   + 425 taxaRateio4_2 * v13_4_2 + 268 taxaRateio4_3 * v13_4_3
   + 630 taxaRateio4_5 * v13_4_5 + 420 taxaRateio5_1 * v13_5_1
   + 250 taxaRateio5_2 * v13_5_2 + 521 taxaRateio5_3 * v13_5_3
   + 520 taxaRateio5_4 * v13_5_4 ] <= 160
 rest12_tarifaMaxPassageiro14: [ 232 taxaRateio1_2 * v14_1_2
   + 665 taxaRateio1_3 * v14_1_3 + 269 taxaRateio1_4 * v14_1_4
   + 376 taxaRateio1_5 * v14_1_5 + 498 taxaRateio2_1 * v14_2_1
   + 270 taxaRateio2_3 * v14_2_3 + 476 taxaRateio2_4 * v14_2_4
   + 296 taxaRateio2_5 * v14_2_5 + 251 taxaRateio3_1 * v14_3_1
   + 440 taxaRateio3_2 * v14_3_2 + 368 taxaRateio3_4 * v14_3_4
   + 434 taxaRateio3_5 * v14_3_5 + 626 taxaRateio4_1 * v14_4_1
   + 425 taxaRateio4_2 * v14_4_2 + 268 taxaRateio4_3 * v14_4_3
   + 630 taxaRateio4_5 * v14_4_5 + 420 taxaRateio5_1 * v14_5_1
   + 250 taxaRateio5_2 * v14_5_2 + 521 taxaRateio5_3 * v14_5_3
   + 520 taxaRateio5_4 * v14_5_4 ] <= 128
 rest12_tarifaMaxPassageiro15: [ 232 taxaRateio1_2 * v15_1_2
   + 665 taxaRateio1_3 * v15_1_3 + 269 taxaRateio1_4 * v15_1_4
   + 376 taxaRateio1_5 * v15_1_5 + 498 taxaRateio2_1 * v15_2_1
   + 270 taxaRateio2_3 * v15_2_3 + 476 taxaRateio2_4 * v15_2_4
   + 296 taxaRateio2_5 * v15_2_5 + 251 taxaRateio3_1 * v15_3_1
   + 440 taxaRateio3_2 * v15_3_2 + 368 taxaRateio3_4 * v15_3_4
   + 434 taxaRateio3_5 * v15_3_5 + 626 taxaRateio4_1 * v15_4_1
   + 425 taxaRateio4_2 * v15_4_2 + 268 taxaRateio4_3 * v15_4_3
   + 630 taxaRateio4_5 * v15_4_5 + 420 taxaRateio5_1 * v15_5_1
   + 250 taxaRateio5_2 * v15_5_2 + 521 taxaRateio5_3 * v15_5_3
   + 520 taxaRateio5_4 * v15_5_4 ] <= 128
 rest13_quantidadeDePassageirosNaAresta1_2: taxaRateio1_2 + [
   taxaRateio1_2 * v1_1_2 + taxaRateio1_2 * v2_1_2 + taxaRateio1_2 * v3_1_2
   + taxaRateio1_2 * v4_1_2 + taxaRateio1_2 * v5_1_2
   + taxaRateio1_2 * v6_1_2 + taxaRateio1_2 * v7_1_2
   + taxaRateio1_2 * v8_1_2 + taxaRateio1_2 * v9_1_2
   + taxaRateio1_2 * v10_1_2 + taxaRateio1_2 * v11_1_2
   + taxaRateio1_2 * v12_1_2 + taxaRateio1_2 * v13_1_2
   + taxaRateio1_2 * v14_1_2 + taxaRateio1_2 * v15_1_2 ] = 1
 rest13_quantidadeDePassageirosNaAresta1_3: taxaRateio1_3 + [
   taxaRateio1_3 * v1_1_3 + taxaRateio1_3 * v2_1_3 + taxaRateio1_3 * v3_1_3
   + taxaRateio1_3 * v4_1_3 + taxaRateio1_3 * v5_1_3
   + taxaRateio1_3 * v6_1_3 + taxaRateio1_3 * v7_1_3
   + taxaRateio1_3 * v8_1_3 + taxaRateio1_3 * v9_1_3
   + taxaRateio1_3 * v10_1_3 + taxaRateio1_3 * v11_1_3
   + taxaRateio1_3 * v12_1_3 + taxaRateio1_3 * v13_1_3
   + taxaRateio1_3 * v14_1_3 + taxaRateio1_3 * v15_1_3 ] = 1
 rest13_quantidadeDePassageirosNaAresta1_4: taxaRateio1_4 + [
   taxaRateio1_4 * v1_1_4 + taxaRateio1_4 * v2_1_4 + taxaRateio1_4 * v3_1_4
   + taxaRateio1_4 * v4_1_4 + taxaRateio1_4 * v5_1_4
   + taxaRateio1_4 * v6_1_4 + taxaRateio1_4 * v7_1_4
   + taxaRateio1_4 * v8_1_4 + taxaRateio1_4 * v9_1_4
   + taxaRateio1_4 * v10_1_4 + taxaRateio1_4 * v11_1_4
   + taxaRateio1_4 * v12_1_4 + taxaRateio1_4 * v13_1_4
   + taxaRateio1_4 * v14_1_4 + taxaRateio1_4 * v15_1_4 ] = 1
 rest13_quantidadeDePassageirosNaAresta1_5: taxaRateio1_5 + [
   taxaRateio1_5 * v1_1_5 + taxaRateio1_5 * v2_1_5 + taxaRateio1_5 * v3_1_5
   + taxaRateio1_5 * v4_1_5 + taxaRateio1_5 * v5_1_5
   + taxaRateio1_5 * v6_1_5 + taxaRateio1_5 * v7_1_5
   + taxaRateio1_5 * v8_1_5 + taxaRateio1_5 * v9_1_5
   + taxaRateio1_5 * v10_1_5 + taxaRateio1_5 * v11_1_5
   + taxaRateio1_5 * v12_1_5 + taxaRateio1_5 * v13_1_5
   + taxaRateio1_5 * v14_1_5 + taxaRateio1_5 * v15_1_5 ] = 1
 rest13_quantidadeDePassageirosNaAresta2_1: taxaRateio2_1 + [
   taxaRateio2_1 * v1_2_1 + taxaRateio2_1 * v2_2_1 + taxaRateio2_1 * v3_2_1
   + taxaRateio2_1 * v4_2_1 + taxaRateio2_1 * v5_2_1
   + taxaRateio2_1 * v6_2_1 + taxaRateio2_1 * v7_2_1
   + taxaRateio2_1 * v8_2_1 + taxaRateio2_1 * v9_2_1
   + taxaRateio2_1 * v10_2_1 + taxaRateio2_1 * v11_2_1
   + taxaRateio2_1 * v12_2_1 + taxaRateio2_1 * v13_2_1
   + taxaRateio2_1 * v14_2_1 + taxaRateio2_1 * v15_2_1 ] = 1
 rest13_quantidadeDePassageirosNaAresta2_3: taxaRateio2_3 + [
   taxaRateio2_3 * v1_2_3 + taxaRateio2_3 * v2_2_3 + taxaRateio2_3 * v3_2_3
   + taxaRateio2_3 * v4_2_3 + taxaRateio2_3 * v5_2_3
   + taxaRateio2_3 * v6_2_3 + taxaRateio2_3 * v7_2_3
   + taxaRateio2_3 * v8_2_3 + taxaRateio2_3 * v9_2_3
   + taxaRateio2_3 * v10_2_3 + taxaRateio2_3 * v11_2_3
   + taxaRateio2_3 * v12_2_3 + taxaRateio2_3 * v13_2_3
   + taxaRateio2_3 * v14_2_3 + taxaRateio2_3 * v15_2_3 ] = 1
 rest13_quantidadeDePassageirosNaAresta2_4: taxaRateio2_4 + [
   taxaRateio2_4 * v1_2_4 + taxaRateio2_4 * v2_2_4 + taxaRateio2_4 * v3_2_4
   + taxaRateio2_4 * v4_2_4 + taxaRateio2_4 * v5_2_4
   + taxaRateio2_4 * v6_2_4 + taxaRateio2_4 * v7_2_4
   + taxaRateio2_4 * v8_2_4 + taxaRateio2_4 * v9_2_4
   + taxaRateio2_4 * v10_2_4 + taxaRateio2_4 * v11_2_4
   + taxaRateio2_4 * v12_2_4 + taxaRateio2_4 * v13_2_4
   + taxaRateio2_4 * v14_2_4 + taxaRateio2_4 * v15_2_4 ] = 1
 rest13_quantidadeDePassageirosNaAresta2_5: taxaRateio2_5 + [
   taxaRateio2_5 * v1_2_5 + taxaRateio2_5 * v2_2_5 + taxaRateio2_5 * v3_2_5
   + taxaRateio2_5 * v4_2_5 + taxaRateio2_5 * v5_2_5
   + taxaRateio2_5 * v6_2_5 + taxaRateio2_5 * v7_2_5
   + taxaRateio2_5 * v8_2_5 + taxaRateio2_5 * v9_2_5
   + taxaRateio2_5 * v10_2_5 + taxaRateio2_5 * v11_2_5
   + taxaRateio2_5 * v12_2_5 + taxaRateio2_5 * v13_2_5
   + taxaRateio2_5 * v14_2_5 + taxaRateio2_5 * v15_2_5 ] = 1
 rest13_quantidadeDePassageirosNaAresta3_1: taxaRateio3_1 + [
   taxaRateio3_1 * v1_3_1 + taxaRateio3_1 * v2_3_1 + taxaRateio3_1 * v3_3_1
   + taxaRateio3_1 * v4_3_1 + taxaRateio3_1 * v5_3_1
   + taxaRateio3_1 * v6_3_1 + taxaRateio3_1 * v7_3_1
   + taxaRateio3_1 * v8_3_1 + taxaRateio3_1 * v9_3_1
   + taxaRateio3_1 * v10_3_1 + taxaRateio3_1 * v11_3_1
   + taxaRateio3_1 * v12_3_1 + taxaRateio3_1 * v13_3_1
   + taxaRateio3_1 * v14_3_1 + taxaRateio3_1 * v15_3_1 ] = 1
 rest13_quantidadeDePassageirosNaAresta3_2: taxaRateio3_2 + [
   taxaRateio3_2 * v1_3_2 + taxaRateio3_2 * v2_3_2 + taxaRateio3_2 * v3_3_2
   + taxaRateio3_2 * v4_3_2 + taxaRateio3_2 * v5_3_2
   + taxaRateio3_2 * v6_3_2 + taxaRateio3_2 * v7_3_2
   + taxaRateio3_2 * v8_3_2 + taxaRateio3_2 * v9_3_2
   + taxaRateio3_2 * v10_3_2 + taxaRateio3_2 * v11_3_2
   + taxaRateio3_2 * v12_3_2 + taxaRateio3_2 * v13_3_2
   + taxaRateio3_2 * v14_3_2 + taxaRateio3_2 * v15_3_2 ] = 1
 rest13_quantidadeDePassageirosNaAresta3_4: taxaRateio3_4 + [
   taxaRateio3_4 * v1_3_4 + taxaRateio3_4 * v2_3_4 + taxaRateio3_4 * v3_3_4
   + taxaRateio3_4 * v4_3_4 + taxaRateio3_4 * v5_3_4
   + taxaRateio3_4 * v6_3_4 + taxaRateio3_4 * v7_3_4
   + taxaRateio3_4 * v8_3_4 + taxaRateio3_4 * v9_3_4
   + taxaRateio3_4 * v10_3_4 + taxaRateio3_4 * v11_3_4
   + taxaRateio3_4 * v12_3_4 + taxaRateio3_4 * v13_3_4
   + taxaRateio3_4 * v14_3_4 + taxaRateio3_4 * v15_3_4 ] = 1
 rest13_quantidadeDePassageirosNaAresta3_5: taxaRateio3_5 + [
   taxaRateio3_5 * v1_3_5 + taxaRateio3_5 * v2_3_5 + taxaRateio3_5 * v3_3_5
   + taxaRateio3_5 * v4_3_5 + taxaRateio3_5 * v5_3_5
   + taxaRateio3_5 * v6_3_5 + taxaRateio3_5 * v7_3_5
   + taxaRateio3_5 * v8_3_5 + taxaRateio3_5 * v9_3_5
   + taxaRateio3_5 * v10_3_5 + taxaRateio3_5 * v11_3_5
   + taxaRateio3_5 * v12_3_5 + taxaRateio3_5 * v13_3_5
   + taxaRateio3_5 * v14_3_5 + taxaRateio3_5 * v15_3_5 ] = 1
 rest13_quantidadeDePassageirosNaAresta4_1: taxaRateio4_1 + [
   taxaRateio4_1 * v1_4_1 + taxaRateio4_1 * v2_4_1 + taxaRateio4_1 * v3_4_1
   + taxaRateio4_1 * v4_4_1 + taxaRateio4_1 * v5_4_1
   + taxaRateio4_1 * v6_4_1 + taxaRateio4_1 * v7_4_1
   + taxaRateio4_1 * v8_4_1 + taxaRateio4_1 * v9_4_1
   + taxaRateio4_1 * v10_4_1 + taxaRateio4_1 * v11_4_1
   + taxaRateio4_1 * v12_4_1 + taxaRateio4_1 * v13_4_1
   + taxaRateio4_1 * v14_4_1 + taxaRateio4_1 * v15_4_1 ] = 1
 rest13_quantidadeDePassageirosNaAresta4_2: taxaRateio4_2 + [
   taxaRateio4_2 * v1_4_2 + taxaRateio4_2 * v2_4_2 + taxaRateio4_2 * v3_4_2
   + taxaRateio4_2 * v4_4_2 + taxaRateio4_2 * v5_4_2
   + taxaRateio4_2 * v6_4_2 + taxaRateio4_2 * v7_4_2
   + taxaRateio4_2 * v8_4_2 + taxaRateio4_2 * v9_4_2
   + taxaRateio4_2 * v10_4_2 + taxaRateio4_2 * v11_4_2
   + taxaRateio4_2 * v12_4_2 + taxaRateio4_2 * v13_4_2
   + taxaRateio4_2 * v14_4_2 + taxaRateio4_2 * v15_4_2 ] = 1
 rest13_quantidadeDePassageirosNaAresta4_3: taxaRateio4_3 + [
   taxaRateio4_3 * v1_4_3 + taxaRateio4_3 * v2_4_3 + taxaRateio4_3 * v3_4_3
   + taxaRateio4_3 * v4_4_3 + taxaRateio4_3 * v5_4_3
   + taxaRateio4_3 * v6_4_3 + taxaRateio4_3 * v7_4_3
   + taxaRateio4_3 * v8_4_3 + taxaRateio4_3 * v9_4_3
   + taxaRateio4_3 * v10_4_3 + taxaRateio4_3 * v11_4_3
   + taxaRateio4_3 * v12_4_3 + taxaRateio4_3 * v13_4_3
   + taxaRateio4_3 * v14_4_3 + taxaRateio4_3 * v15_4_3 ] = 1
 rest13_quantidadeDePassageirosNaAresta4_5: taxaRateio4_5 + [
   taxaRateio4_5 * v1_4_5 + taxaRateio4_5 * v2_4_5 + taxaRateio4_5 * v3_4_5
   + taxaRateio4_5 * v4_4_5 + taxaRateio4_5 * v5_4_5
   + taxaRateio4_5 * v6_4_5 + taxaRateio4_5 * v7_4_5
   + taxaRateio4_5 * v8_4_5 + taxaRateio4_5 * v9_4_5
   + taxaRateio4_5 * v10_4_5 + taxaRateio4_5 * v11_4_5
   + taxaRateio4_5 * v12_4_5 + taxaRateio4_5 * v13_4_5
   + taxaRateio4_5 * v14_4_5 + taxaRateio4_5 * v15_4_5 ] = 1
 rest13_quantidadeDePassageirosNaAresta5_1: taxaRateio5_1 + [
   taxaRateio5_1 * v1_5_1 + taxaRateio5_1 * v2_5_1 + taxaRateio5_1 * v3_5_1
   + taxaRateio5_1 * v4_5_1 + taxaRateio5_1 * v5_5_1
   + taxaRateio5_1 * v6_5_1 + taxaRateio5_1 * v7_5_1
   + taxaRateio5_1 * v8_5_1 + taxaRateio5_1 * v9_5_1
   + taxaRateio5_1 * v10_5_1 + taxaRateio5_1 * v11_5_1
   + taxaRateio5_1 * v12_5_1 + taxaRateio5_1 * v13_5_1
   + taxaRateio5_1 * v14_5_1 + taxaRateio5_1 * v15_5_1 ] = 1
 rest13_quantidadeDePassageirosNaAresta5_2: taxaRateio5_2 + [
   taxaRateio5_2 * v1_5_2 + taxaRateio5_2 * v2_5_2 + taxaRateio5_2 * v3_5_2
   + taxaRateio5_2 * v4_5_2 + taxaRateio5_2 * v5_5_2
   + taxaRateio5_2 * v6_5_2 + taxaRateio5_2 * v7_5_2
   + taxaRateio5_2 * v8_5_2 + taxaRateio5_2 * v9_5_2
   + taxaRateio5_2 * v10_5_2 + taxaRateio5_2 * v11_5_2
   + taxaRateio5_2 * v12_5_2 + taxaRateio5_2 * v13_5_2
   + taxaRateio5_2 * v14_5_2 + taxaRateio5_2 * v15_5_2 ] = 1
 rest13_quantidadeDePassageirosNaAresta5_3: taxaRateio5_3 + [
   taxaRateio5_3 * v1_5_3 + taxaRateio5_3 * v2_5_3 + taxaRateio5_3 * v3_5_3
   + taxaRateio5_3 * v4_5_3 + taxaRateio5_3 * v5_5_3
   + taxaRateio5_3 * v6_5_3 + taxaRateio5_3 * v7_5_3
   + taxaRateio5_3 * v8_5_3 + taxaRateio5_3 * v9_5_3
   + taxaRateio5_3 * v10_5_3 + taxaRateio5_3 * v11_5_3
   + taxaRateio5_3 * v12_5_3 + taxaRateio5_3 * v13_5_3
   + taxaRateio5_3 * v14_5_3 + taxaRateio5_3 * v15_5_3 ] = 1
 rest13_quantidadeDePassageirosNaAresta5_4: taxaRateio5_4 + [
   taxaRateio5_4 * v1_5_4 + taxaRateio5_4 * v2_5_4 + taxaRateio5_4 * v3_5_4
   + taxaRateio5_4 * v4_5_4 + taxaRateio5_4 * v5_5_4
   + taxaRateio5_4 * v6_5_4 + taxaRateio5_4 * v7_5_4
   + taxaRateio5_4 * v8_5_4 + taxaRateio5_4 * v9_5_4
   + taxaRateio5_4 * v10_5_4 + taxaRateio5_4 * v11_5_4
   + taxaRateio5_4 * v12_5_4 + taxaRateio5_4 * v13_5_4
   + taxaRateio5_4 * v14_5_4 + taxaRateio5_4 * v15_5_4 ] = 1
 rest16_passageiroEmbarcadoProssegueEmbarcado1_2: - f1_2 + v1_1_2 - v1_2_1
   - v1_2_3 - v1_2_4 - v1_2_5 + v1_3_2 + v1_4_2 + v1_5_2 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado1_3: - f1_3 + v1_1_3 + v1_2_3
   - v1_3_1 - v1_3_2 - v1_3_4 - v1_3_5 + v1_4_3 + v1_5_3 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado1_4: - f1_4 + v1_1_4 + v1_2_4
   + v1_3_4 - v1_4_1 - v1_4_2 - v1_4_3 - v1_4_5 + v1_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado1_5: - f1_5 + v1_1_5 + v1_2_5
   + v1_3_5 + v1_4_5 - v1_5_1 - v1_5_2 - v1_5_3 - v1_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado2_2: - f2_2 + v2_1_2 - v2_2_1
   - v2_2_3 - v2_2_4 - v2_2_5 + v2_3_2 + v2_4_2 + v2_5_2 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado2_3: - f2_3 + v2_1_3 + v2_2_3
   - v2_3_1 - v2_3_2 - v2_3_4 - v2_3_5 + v2_4_3 + v2_5_3 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado2_4: - f2_4 + v2_1_4 + v2_2_4
   + v2_3_4 - v2_4_1 - v2_4_2 - v2_4_3 - v2_4_5 + v2_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado2_5: - f2_5 + v2_1_5 + v2_2_5
   + v2_3_5 + v2_4_5 - v2_5_1 - v2_5_2 - v2_5_3 - v2_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado3_2: - f3_2 + v3_1_2 - v3_2_1
   - v3_2_3 - v3_2_4 - v3_2_5 + v3_3_2 + v3_4_2 + v3_5_2 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado3_3: - f3_3 + v3_1_3 + v3_2_3
   - v3_3_1 - v3_3_2 - v3_3_4 - v3_3_5 + v3_4_3 + v3_5_3 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado3_4: - f3_4 + v3_1_4 + v3_2_4
   + v3_3_4 - v3_4_1 - v3_4_2 - v3_4_3 - v3_4_5 + v3_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado3_5: - f3_5 + v3_1_5 + v3_2_5
   + v3_3_5 + v3_4_5 - v3_5_1 - v3_5_2 - v3_5_3 - v3_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado4_1: - f4_1 - v4_1_2 - v4_1_3
   - v4_1_4 - v4_1_5 + v4_2_1 + v4_3_1 + v4_4_1 + v4_5_1 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado4_3: - f4_3 + v4_1_3 + v4_2_3
   - v4_3_1 - v4_3_2 - v4_3_4 - v4_3_5 + v4_4_3 + v4_5_3 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado4_4: - f4_4 + v4_1_4 + v4_2_4
   + v4_3_4 - v4_4_1 - v4_4_2 - v4_4_3 - v4_4_5 + v4_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado4_5: - f4_5 + v4_1_5 + v4_2_5
   + v4_3_5 + v4_4_5 - v4_5_1 - v4_5_2 - v4_5_3 - v4_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado5_1: - f5_1 - v5_1_2 - v5_1_3
   - v5_1_4 - v5_1_5 + v5_2_1 + v5_3_1 + v5_4_1 + v5_5_1 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado5_3: - f5_3 + v5_1_3 + v5_2_3
   - v5_3_1 - v5_3_2 - v5_3_4 - v5_3_5 + v5_4_3 + v5_5_3 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado5_4: - f5_4 + v5_1_4 + v5_2_4
   + v5_3_4 - v5_4_1 - v5_4_2 - v5_4_3 - v5_4_5 + v5_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado5_5: - f5_5 + v5_1_5 + v5_2_5
   + v5_3_5 + v5_4_5 - v5_5_1 - v5_5_2 - v5_5_3 - v5_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado6_1: - f6_1 - v6_1_2 - v6_1_3
   - v6_1_4 - v6_1_5 + v6_2_1 + v6_3_1 + v6_4_1 + v6_5_1 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado6_3: - f6_3 + v6_1_3 + v6_2_3
   - v6_3_1 - v6_3_2 - v6_3_4 - v6_3_5 + v6_4_3 + v6_5_3 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado6_4: - f6_4 + v6_1_4 + v6_2_4
   + v6_3_4 - v6_4_1 - v6_4_2 - v6_4_3 - v6_4_5 + v6_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado6_5: - f6_5 + v6_1_5 + v6_2_5
   + v6_3_5 + v6_4_5 - v6_5_1 - v6_5_2 - v6_5_3 - v6_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado7_1: - f7_1 - v7_1_2 - v7_1_3
   - v7_1_4 - v7_1_5 + v7_2_1 + v7_3_1 + v7_4_1 + v7_5_1 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado7_2: - f7_2 + v7_1_2 - v7_2_1
   - v7_2_3 - v7_2_4 - v7_2_5 + v7_3_2 + v7_4_2 + v7_5_2 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado7_4: - f7_4 + v7_1_4 + v7_2_4
   + v7_3_4 - v7_4_1 - v7_4_2 - v7_4_3 - v7_4_5 + v7_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado7_5: - f7_5 + v7_1_5 + v7_2_5
   + v7_3_5 + v7_4_5 - v7_5_1 - v7_5_2 - v7_5_3 - v7_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado8_1: - f8_1 - v8_1_2 - v8_1_3
   - v8_1_4 - v8_1_5 + v8_2_1 + v8_3_1 + v8_4_1 + v8_5_1 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado8_2: - f8_2 + v8_1_2 - v8_2_1
   - v8_2_3 - v8_2_4 - v8_2_5 + v8_3_2 + v8_4_2 + v8_5_2 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado8_4: - f8_4 + v8_1_4 + v8_2_4
   + v8_3_4 - v8_4_1 - v8_4_2 - v8_4_3 - v8_4_5 + v8_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado8_5: - f8_5 + v8_1_5 + v8_2_5
   + v8_3_5 + v8_4_5 - v8_5_1 - v8_5_2 - v8_5_3 - v8_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado9_1: - f9_1 - v9_1_2 - v9_1_3
   - v9_1_4 - v9_1_5 + v9_2_1 + v9_3_1 + v9_4_1 + v9_5_1 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado9_2: - f9_2 + v9_1_2 - v9_2_1
   - v9_2_3 - v9_2_4 - v9_2_5 + v9_3_2 + v9_4_2 + v9_5_2 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado9_4: - f9_4 + v9_1_4 + v9_2_4
   + v9_3_4 - v9_4_1 - v9_4_2 - v9_4_3 - v9_4_5 + v9_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado9_5: - f9_5 + v9_1_5 + v9_2_5
   + v9_3_5 + v9_4_5 - v9_5_1 - v9_5_2 - v9_5_3 - v9_5_4 + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado10_1: - f10_1 - v10_1_2
   - v10_1_3 - v10_1_4 - v10_1_5 + v10_2_1 + v10_3_1 + v10_4_1 + v10_5_1
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado10_2: - f10_2 + v10_1_2
   - v10_2_1 - v10_2_3 - v10_2_4 - v10_2_5 + v10_3_2 + v10_4_2 + v10_5_2
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado10_3: - f10_3 + v10_1_3
   + v10_2_3 - v10_3_1 - v10_3_2 - v10_3_4 - v10_3_5 + v10_4_3 + v10_5_3
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado10_5: - f10_5 + v10_1_5
   + v10_2_5 + v10_3_5 + v10_4_5 - v10_5_1 - v10_5_2 - v10_5_3 - v10_5_4
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado11_1: - f11_1 - v11_1_2
   - v11_1_3 - v11_1_4 - v11_1_5 + v11_2_1 + v11_3_1 + v11_4_1 + v11_5_1
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado11_2: - f11_2 + v11_1_2
   - v11_2_1 - v11_2_3 - v11_2_4 - v11_2_5 + v11_3_2 + v11_4_2 + v11_5_2
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado11_3: - f11_3 + v11_1_3
   + v11_2_3 - v11_3_1 - v11_3_2 - v11_3_4 - v11_3_5 + v11_4_3 + v11_5_3
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado11_5: - f11_5 + v11_1_5
   + v11_2_5 + v11_3_5 + v11_4_5 - v11_5_1 - v11_5_2 - v11_5_3 - v11_5_4
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado12_1: - f12_1 - v12_1_2
   - v12_1_3 - v12_1_4 - v12_1_5 + v12_2_1 + v12_3_1 + v12_4_1 + v12_5_1
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado12_2: - f12_2 + v12_1_2
   - v12_2_1 - v12_2_3 - v12_2_4 - v12_2_5 + v12_3_2 + v12_4_2 + v12_5_2
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado12_3: - f12_3 + v12_1_3
   + v12_2_3 - v12_3_1 - v12_3_2 - v12_3_4 - v12_3_5 + v12_4_3 + v12_5_3
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado12_5: - f12_5 + v12_1_5
   + v12_2_5 + v12_3_5 + v12_4_5 - v12_5_1 - v12_5_2 - v12_5_3 - v12_5_4
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado13_1: - f13_1 - v13_1_2
   - v13_1_3 - v13_1_4 - v13_1_5 + v13_2_1 + v13_3_1 + v13_4_1 + v13_5_1
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado13_2: - f13_2 + v13_1_2
   - v13_2_1 - v13_2_3 - v13_2_4 - v13_2_5 + v13_3_2 + v13_4_2 + v13_5_2
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado13_3: - f13_3 + v13_1_3
   + v13_2_3 - v13_3_1 - v13_3_2 - v13_3_4 - v13_3_5 + v13_4_3 + v13_5_3
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado13_4: - f13_4 + v13_1_4
   + v13_2_4 + v13_3_4 - v13_4_1 - v13_4_2 - v13_4_3 - v13_4_5 + v13_5_4
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado14_1: - f14_1 - v14_1_2
   - v14_1_3 - v14_1_4 - v14_1_5 + v14_2_1 + v14_3_1 + v14_4_1 + v14_5_1
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado14_2: - f14_2 + v14_1_2
   - v14_2_1 - v14_2_3 - v14_2_4 - v14_2_5 + v14_3_2 + v14_4_2 + v14_5_2
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado14_3: - f14_3 + v14_1_3
   + v14_2_3 - v14_3_1 - v14_3_2 - v14_3_4 - v14_3_5 + v14_4_3 + v14_5_3
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado14_4: - f14_4 + v14_1_4
   + v14_2_4 + v14_3_4 - v14_4_1 - v14_4_2 - v14_4_3 - v14_4_5 + v14_5_4
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado15_1: - f15_1 - v15_1_2
   - v15_1_3 - v15_1_4 - v15_1_5 + v15_2_1 + v15_3_1 + v15_4_1 + v15_5_1
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado15_2: - f15_2 + v15_1_2
   - v15_2_1 - v15_2_3 - v15_2_4 - v15_2_5 + v15_3_2 + v15_4_2 + v15_5_2
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado15_3: - f15_3 + v15_1_3
   + v15_2_3 - v15_3_1 - v15_3_2 - v15_3_4 - v15_3_5 + v15_4_3 + v15_5_3
   + [ ] = -0
 rest16_passageiroEmbarcadoProssegueEmbarcado15_4: - f15_4 + v15_1_4
   + v15_2_4 + v15_3_4 - v15_4_1 - v15_4_2 - v15_4_3 - v15_4_5 + v15_5_4
   + [ ] = -0
Bounds
 x1_1 = 0
 x2_2 = 0
 x3_3 = 0
 x4_4 = 0
 x5_5 = 0
 u1 = 0
 u2 <= 4
 u3 <= 4
 u4 <= 4
 u5 <= 4
 taxaRateio1_1 = 0
 taxaRateio1_2 <= 1
 taxaRateio1_3 <= 1
 taxaRateio1_4 <= 1
 taxaRateio1_5 <= 1
 taxaRateio2_1 <= 1
 taxaRateio2_2 = 0
 taxaRateio2_3 <= 1
 taxaRateio2_4 <= 1
 taxaRateio2_5 <= 1
 taxaRateio3_1 <= 1
 taxaRateio3_2 <= 1
 taxaRateio3_3 = 0
 taxaRateio3_4 <= 1
 taxaRateio3_5 <= 1
 taxaRateio4_1 <= 1
 taxaRateio4_2 <= 1
 taxaRateio4_3 <= 1
 taxaRateio4_4 = 0
 taxaRateio4_5 <= 1
 taxaRateio5_1 <= 1
 taxaRateio5_2 <= 1
 taxaRateio5_3 <= 1
 taxaRateio5_4 <= 1
 taxaRateio5_5 = 0
 p1 = 0
Binaries
 x1_1 x1_2 x1_3 x1_4 x1_5 x2_1 x2_2 x2_3 x2_4 x2_5 x3_1 x3_2 x3_3 x3_4 x3_5
 x4_1 x4_2 x4_3 x4_4 x4_5 x5_1 x5_2 x5_3 x5_4 x5_5 p1 p2 p3 p4 p5 q1 q2 q3
 q4 q5 q6 q7 q8 q9 q10 q11 q12 q13 q14 q15 f1_1 f1_2 f1_3 f1_4 f1_5 f2_1
 f2_2 f2_3 f2_4 f2_5 f3_1 f3_2 f3_3 f3_4 f3_5 f4_1 f4_2 f4_3 f4_4 f4_5 f5_1
 f5_2 f5_3 f5_4 f5_5 f6_1 f6_2 f6_3 f6_4 f6_5 f7_1 f7_2 f7_3 f7_4 f7_5 f8_1
 f8_2 f8_3 f8_4 f8_5 f9_1 f9_2 f9_3 f9_4 f9_5 f10_1 f10_2 f10_3 f10_4 f10_5
 f11_1 f11_2 f11_3 f11_4 f11_5 f12_1 f12_2 f12_3 f12_4 f12_5 f13_1 f13_2
 f13_3 f13_4 f13_5 f14_1 f14_2 f14_3 f14_4 f14_5 f15_1 f15_2 f15_3 f15_4
 f15_5 v1_1_1 v1_1_2 v1_1_3 v1_1_4 v1_1_5 v1_2_1 v1_2_2 v1_2_3 v1_2_4
 v1_2_5 v1_3_1 v1_3_2 v1_3_3 v1_3_4 v1_3_5 v1_4_1 v1_4_2 v1_4_3 v1_4_4
 v1_4_5 v1_5_1 v1_5_2 v1_5_3 v1_5_4 v1_5_5 v2_1_1 v2_1_2 v2_1_3 v2_1_4
 v2_1_5 v2_2_1 v2_2_2 v2_2_3 v2_2_4 v2_2_5 v2_3_1 v2_3_2 v2_3_3 v2_3_4
 v2_3_5 v2_4_1 v2_4_2 v2_4_3 v2_4_4 v2_4_5 v2_5_1 v2_5_2 v2_5_3 v2_5_4
 v2_5_5 v3_1_1 v3_1_2 v3_1_3 v3_1_4 v3_1_5 v3_2_1 v3_2_2 v3_2_3 v3_2_4
 v3_2_5 v3_3_1 v3_3_2 v3_3_3 v3_3_4 v3_3_5 v3_4_1 v3_4_2 v3_4_3 v3_4_4
 v3_4_5 v3_5_1 v3_5_2 v3_5_3 v3_5_4 v3_5_5 v4_1_1 v4_1_2 v4_1_3 v4_1_4
 v4_1_5 v4_2_1 v4_2_2 v4_2_3 v4_2_4 v4_2_5 v4_3_1 v4_3_2 v4_3_3 v4_3_4
 v4_3_5 v4_4_1 v4_4_2 v4_4_3 v4_4_4 v4_4_5 v4_5_1 v4_5_2 v4_5_3 v4_5_4
 v4_5_5 v5_1_1 v5_1_2 v5_1_3 v5_1_4 v5_1_5 v5_2_1 v5_2_2 v5_2_3 v5_2_4
 v5_2_5 v5_3_1 v5_3_2 v5_3_3 v5_3_4 v5_3_5 v5_4_1 v5_4_2 v5_4_3 v5_4_4
 v5_4_5 v5_5_1 v5_5_2 v5_5_3 v5_5_4 v5_5_5 v6_1_1 v6_1_2 v6_1_3 v6_1_4
 v6_1_5 v6_2_1 v6_2_2 v6_2_3 v6_2_4 v6_2_5 v6_3_1 v6_3_2 v6_3_3 v6_3_4
 v6_3_5 v6_4_1 v6_4_2 v6_4_3 v6_4_4 v6_4_5 v6_5_1 v6_5_2 v6_5_3 v6_5_4
 v6_5_5 v7_1_1 v7_1_2 v7_1_3 v7_1_4 v7_1_5 v7_2_1 v7_2_2 v7_2_3 v7_2_4
 v7_2_5 v7_3_1 v7_3_2 v7_3_3 v7_3_4 v7_3_5 v7_4_1 v7_4_2 v7_4_3 v7_4_4
 v7_4_5 v7_5_1 v7_5_2 v7_5_3 v7_5_4 v7_5_5 v8_1_1 v8_1_2 v8_1_3 v8_1_4
 v8_1_5 v8_2_1 v8_2_2 v8_2_3 v8_2_4 v8_2_5 v8_3_1 v8_3_2 v8_3_3 v8_3_4
 v8_3_5 v8_4_1 v8_4_2 v8_4_3 v8_4_4 v8_4_5 v8_5_1 v8_5_2 v8_5_3 v8_5_4
 v8_5_5 v9_1_1 v9_1_2 v9_1_3 v9_1_4 v9_1_5 v9_2_1 v9_2_2 v9_2_3 v9_2_4
 v9_2_5 v9_3_1 v9_3_2 v9_3_3 v9_3_4 v9_3_5 v9_4_1 v9_4_2 v9_4_3 v9_4_4
 v9_4_5 v9_5_1 v9_5_2 v9_5_3 v9_5_4 v9_5_5 v10_1_1 v10_1_2 v10_1_3 v10_1_4
 v10_1_5 v10_2_1 v10_2_2 v10_2_3 v10_2_4 v10_2_5 v10_3_1 v10_3_2 v10_3_3
 v10_3_4 v10_3_5 v10_4_1 v10_4_2 v10_4_3 v10_4_4 v10_4_5 v10_5_1 v10_5_2
 v10_5_3 v10_5_4 v10_5_5 v11_1_1 v11_1_2 v11_1_3 v11_1_4 v11_1_5 v11_2_1
 v11_2_2 v11_2_3 v11_2_4 v11_2_5 v11_3_1 v11_3_2 v11_3_3 v11_3_4 v11_3_5
 v11_4_1 v11_4_2 v11_4_3 v11_4_4 v11_4_5 v11_5_1 v11_5_2 v11_5_3 v11_5_4
 v11_5_5 v12_1_1 v12_1_2 v12_1_3 v12_1_4 v12_1_5 v12_2_1 v12_2_2 v12_2_3
 v12_2_4 v12_2_5 v12_3_1 v12_3_2 v12_3_3 v12_3_4 v12_3_5 v12_4_1 v12_4_2
 v12_4_3 v12_4_4 v12_4_5 v12_5_1 v12_5_2 v12_5_3 v12_5_4 v12_5_5 v13_1_1
 v13_1_2 v13_1_3 v13_1_4 v13_1_5 v13_2_1 v13_2_2 v13_2_3 v13_2_4 v13_2_5
 v13_3_1 v13_3_2 v13_3_3 v13_3_4 v13_3_5 v13_4_1 v13_4_2 v13_4_3 v13_4_4
 v13_4_5 v13_5_1 v13_5_2 v13_5_3 v13_5_4 v13_5_5 v14_1_1 v14_1_2 v14_1_3
 v14_1_4 v14_1_5 v14_2_1 v14_2_2 v14_2_3 v14_2_4 v14_2_5 v14_3_1 v14_3_2
 v14_3_3 v14_3_4 v14_3_5 v14_4_1 v14_4_2 v14_4_3 v14_4_4 v14_4_5 v14_5_1
 v14_5_2 v14_5_3 v14_5_4 v14_5_5 v15_1_1 v15_1_2 v15_1_3 v15_1_4 v15_1_5
 v15_2_1 v15_2_2 v15_2_3 v15_2_4 v15_2_5 v15_3_1 v15_3_2 v15_3_3 v15_3_4
 v15_3_5 v15_4_1 v15_4_2 v15_4_3 v15_4_4 v15_4_5 v15_5_1 v15_5_2 v15_5_3
 v15_5_4 v15_5_5
Generals
 u1 u2 u3 u4 u5
End
