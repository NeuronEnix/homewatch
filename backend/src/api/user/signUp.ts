import {T_Request} from "../../types.js";
import Ajv from "ajv";
const ajv = new Ajv({allErrors: true});

type T_InData = {
  email: string,
  password: string
}

type T_OutData = {
  userId: number,
  accessToken: string,
  refreshToken: string,
}

const ajvValidator = ajv.compile({
  type: "object",
  properties: {
    email: {type: "string"},
    password: {type: "string"}
  },
  required: ["email", "password"],
  additionalProperties: false
});


async function validate (req: T_Request): Promise<T_InData> {
  const dataValidated = ajvValidator(req.body);
  if (!dataValidated) {
    console.log(ajvValidator.errors);
    throw ajvValidator.errors;
  }
  return req.body as T_InData;
}

async function authorize (data: T_InData): Promise<T_InData> {
  return data;
}

async function execute (data: T_InData): Promise<T_OutData> {
  data.email;
  return {userId: 1, accessToken: "acc", refreshToken: "ref"};
}

export default async function getWaterTankList (req: T_Request): Promise<T_OutData> {
  return validate(req).then(authorize).then(execute);
}
