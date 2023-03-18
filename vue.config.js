const { defineConfig } = require('@vue/cli-service')
module.exports = defineConfig({
  transpileDependencies: [
    'quasar'
  ],

  pluginOptions: {
    quasar: {
      importStrategy: 'kebab',
      rtlSupport: false
    },
    electronBuilder: {
      nodeIntegration: true,
      externals: ['serialport'],
      customFileProtocol: './',
      builderOptions: {
        appId: 'test.com',
        win: {
          icon: 'public/icon.png',
          target: "portable"
        },
        linux: {
          icon: 'public/icon.icns',
        }
      },
      
    }
  }
})