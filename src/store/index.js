import { createStore } from 'vuex'

const default_port = { 
  locationId: "",  
  manufacturer: "",  
  path: "asd",
  pnpId: "",
  productId: "",
  serialNumber: "",
  vendorId: "" 
}


export default createStore({
  state: {
    port: default_port,
  },
  getters: {
    port(state) {
      return state.port;
    },
  },
  mutations: {
    setPort(state, port) {
        state.port = port
    },
  },
  actions: {
  },
  modules: {
  }
})
