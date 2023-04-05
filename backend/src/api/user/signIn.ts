import {T_Request} from "../../types.js";
type T_InData = {
  waterTankId: number
}

type T_OutData = {
  userId: number,
  accessToken: string,
  refreshToken: string,
}

async function validate (req: T_Request): Promise<T_InData> {
  return {waterTankId: 1};
}

async function authorize (data: T_InData): Promise<T_InData> {
  return data;
}

async function logic (data: T_InData): Promise<T_OutData> {
  return {userId: 1, accessToken: "acc", refreshToken: "ref"};
}

export default async function getWaterTankList (req: T_Request): Promise<T_OutData> {
  return validate(req)
    .then(authorize)
    .then(logic);
}
